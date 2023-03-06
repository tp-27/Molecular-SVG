import molecule
import math

radius = { 'H': 25,
           'C': 40,
           'O': 40,
           'N': 40,
};

element_name = { 'H': 'grey', 'C': 'black',
'O': 'red',
                 'N': 'blue',
               }

header = """<svg version="1.1" width="1000" height="1000" xmlns="http://www.w3.org/2000/svg">"""
footer = """</svg>"""
offsetx = 500
offsety = 500


#create an atom class
class Atom():
    def __init__(self, c_atom):
        self.atom = c_atom #store atom class/struct as member variable
        self.z = c_atom.z #initialize z to be value in wrapped class/struct

    def __svg__(self):
        xCenter = (self.atom.x * 100) + offsetx
        yCenter = (self.atom.y * 100) + offsety
        radiusAtom = radius[self.atom.element]
        colour = element_name[self.atom.element]
        return '''  <circle cx="%.2f" cy="%.2f" r="%d" fill="%s"/>\n''' % (xCenter, yCenter, radiusAtom, colour)

    #debugging method
    def __str__(self):
        return '''Element: %s, x: %f, y: %f, z: %f''' % (self.atom.element, self.atom.x,  self.atom.y,  self.atom.z)


#create a bond class
class Bond():
    def __init__(self, c_bond):
        self.bond = c_bond
        self.z = c_bond.z

    def __svg__(self):

        c1_x = (self.bond.x1 * 100 + offsetx) + self.bond.dy * 10.0
        c1_y = (self.bond.y1 * 100 + offsety) - self.bond.dx * 10.0

        c2_x = (self.bond.x1 * 100 + offsetx) - self.bond.dy * 10.0
        c2_y = (self.bond.y1 * 100 + offsety) + self.bond.dx * 10.0

        c3_x = (self.bond.x2 * 100 + offsetx) - self.bond.dy * 10.0
        c3_y = (self.bond.y2 * 100 + offsety) + self.bond.dx * 10.0

        c4_x = (self.bond.x2 * 100 + offsetx) + self.bond.dy * 10.0
        c4_y = (self.bond.y2 * 100 + offsety) - self.bond.dx * 10.0


        return '''  <polygon points="%.2f,%.2f %.2f,%.2f %.2f,%.2f %.2f,%.2f" fill="green"/>\n''' % (c1_x, c1_y, c2_x, c2_y, c3_x, c3_y,
        c4_x, c4_y)
        
    def __str__(self):
        return '''a1: %d, a2: %d, epairs: %d, x1: %f ,x2: %f, y1: %f, y2: %f, 
        z: %f, len: %f, dx: %f, dy: %f''' % (self.bond.a1, self.bond.a2, self.bond.epairs, self.bond.x1, self.bond.x2,
        self.bond.y1, self.bond.y2, self.bond.z, self.bond.len, self.bond.dx, self.bond.dy)

#create a molecule class
class Molecule(molecule.molecule):
    def __init__(self):
        self.mol = molecule.molecule()
        super().__init__()

    def __str__(self):
        #print atoms
        print(self.mol.atom_no)
        for i in range(self.mol.atom_no):
            theAtom = self.mol.get_atom(i)
            print('''%s: x: %f, y: %f, z: %f ''' % (theAtom.element, theAtom.x, theAtom.y, theAtom.z))

        #print bonds
        for i in range(self.mol.bond_no):
            theBond = self.mol.get_bond(i)
            theAtom1 = self.mol.get_atom(theBond.a1)
            theAtom2 = self.mol.get_atom(theBond.a2)
            print('''Bond %d: %s + %s , Epairs: %d, z: %f, len: %f, dx: %f, dy: %f''' % (i, theAtom1.element, theAtom2.element, theBond.epairs,
            theBond.z, theBond.len, theBond.dx, theBond.dy))


    def svg(self):
        atoms = []
        bonds = []
        svgList = []

        atom_no = self.mol.atom_no 
        bond_no = self.mol.bond_no

        #create atoms and bonds stack - largest z value on top
        for i in range(atom_no): 
            atoms.append(self.mol.get_atom(i))

        for i in range(bond_no):
            bonds.append(self.mol.get_bond(i))

        #create one stack with atom and bond z values sorted
        i = 0
        j = 0
        while (i < atom_no and j < bond_no):
            if (atoms[i].z > bonds[j].z):
                svgList.append(bonds[j])
                j += 1
            
            else:
                svgList.append(atoms[i])
                i += 1

        while (i < atom_no):
            svgList.append(atoms[i])
            i += 1

        while (j < bond_no):
            svgList.append(bonds[j])
            j += 1

        #append values to svg string
        svgString = header #append header
        for i in range(atom_no + bond_no):
            object = svgList[i]
            if (type(object) == molecule.atom):
                theAtom = Atom(object)
                theSvg = theAtom.__svg__()

            else:
                theBond = Bond(object)
                theSvg = theBond.__svg__()

            svgString += theSvg

        svgString += footer
        return svgString
            
    def parse(self, fileObj): #takes in file object, supposing file is already opened when passed to func
        contents = fileObj.readlines()
        
        molecule_info = contents[3]
        molecule_info = molecule_info.split(' ')
        molecule_info[:] = [item for item in molecule_info if item != '']
        atom_no = int(molecule_info[0])
        bond_no = int(molecule_info[1])

        # parse atoms
        for i in range(atom_no):
            atom_line = contents[i + 4].split(' ')
            atom_line[:] = [item for item in atom_line if item != '']
            
            x = float(atom_line[0])
            y = float(atom_line[1])
            z = float(atom_line[2])
            element = atom_line[3]            
            self.mol.append_atom(element, x, y, z)
 
        #parse bonds
        for i in range(bond_no):
            bond_line = contents[i + 4 + atom_no].split(' ')
            bond_line[:] = [item for item in bond_line if item != '']

            a1 = int(bond_line[0])
            a2 = int(bond_line[1])
            epairs = int(bond_line[2])
            self.mol.append_bond(a1, a2, epairs)

        self.mol.sort()
