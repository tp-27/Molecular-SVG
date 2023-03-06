/***********************************************
             mol Library 
***********************************************/
#ifndef _mol_h
#define _mol_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

/***********************************************
             Structs/Typedefs
***********************************************/

/**
 * atom - defines structure that describes atom in 3D space
 *     element: element name
 *     x,y,z: position parameters (Angstroms)
 **/
typedef struct atom
{
    char element[3];
    double x, y, z;
} atom;


/**
 * bond - defines a co-valent bond between two atoms
 *     a1, a2: indices of two atoms in co-valent bond within an array with address atoms
 *     epairs: number of electron pairs in bond
 *     atoms: stores an array of atoms within a molecule 
 *     x1,x2,y1,y2: store x and y coordinates of atoms a1, a2 respectively
 *     len: stores distance from a1 to a2
 *     dx, dy: store differences between x and y values of a2 and a1 , divided by the length of the bond 
 **/
typedef struct bond
{
    unsigned short a1, a2;
    unsigned char epairs;
    atom *atoms;
    double x1, x2, y1, y2, z, len, dx, dy;
} bond;

/**
 * molecule - defines molecule consisting of atoms
 *     atom_max: records dimensionality of array pointed to by atoms
 *     atom_no: number of atoms currently stored in array atoms
 *     bond_max: records dimensionality of array pointed to by bonds
 *     bond_no: atom_no: number of bonds currently stored in array bonds
 *     atom_ptrs, bond_ptrs: array of pointers
 **/
typedef struct molecule
{
    unsigned short atom_max, atom_no;
    atom *atoms, **atom_ptrs;
    unsigned short bond_max, bond_no;
    bond *bonds, **bond_ptrs;
} molecule;


/**
 * xform_matrix - defines 3D affine transformation matrix
 **/
typedef double xform_matrix[3][3];


/***********************************************
             mol Library ProtoTypes
***********************************************/
void atomset(atom *atom, char element[3], double *x, double *y, double *z);

void atomget(atom *atom, char element[3], double *x, double *y, double *z);

void bondset(bond *bond, unsigned short *a1, unsigned short *a2, atom **atoms, unsigned char *epairs);

void bondget(bond *bond, unsigned short *a1, unsigned short *a2, atom **atoms, unsigned char *epairs);

molecule *molmalloc(unsigned short atom_max, unsigned short bond_max);

molecule *molcopy(molecule *src);

void molfree(molecule *ptr);

void molappend_atom(molecule *molecule, atom *atom);

void molappend_bond(molecule *molecule, bond *bond);

void molsort(molecule *molecule);

void xrotation(xform_matrix xform_matrix, unsigned short deg);

void yrotation(xform_matrix xform_matrix, unsigned short deg);

void zrotation(xform_matrix xform_matrix, unsigned short deg);

void mol_xform(molecule *molecule, xform_matrix matrix);

void compute_coords(bond *bond);


/***********************************************
             Helper Library ProtoTypes
***********************************************/
int atom_comp(const void *a, const void *b);

int bond_comp (const void *a, const void *b);

#endif