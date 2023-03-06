import sys
import MolDisplay
import io
from http.server import HTTPServer, BaseHTTPRequestHandler

class MyHandler( BaseHTTPRequestHandler ):
    def do_GET(self):
        if self.path == "/":
            self.send_response( 200 ) # OK
            self.send_header( "Content-type", "text/html" )
            self.end_headers()
            self.wfile.write(bytes( home_page, "UTF-8" ))

        else:
            self.send_response(404)
            self.end_headers()
            self.wfile.write( bytes("404: not found", "UTF-8"))

    def do_POST(self):
      if self.path == "/molecule":
        content_length = int(self.headers['content-length'])
        postdata = self.rfile.read(content_length).decode("UTF-8")
        postdata = postdata.split("\n",4)[4]

        bytesIO = io.BytesIO(bytes(postdata, "UTF-8"))
        textIO = io.TextIOWrapper(bytesIO)

        molObj = MolDisplay.Molecule()
        molObj.parse(textIO)
        molObj.sort()
        svg_file = molObj.svg()

        self.send_response(200)
        self.send_header("Content-type", "image/svg+xml")
        self.end_headers()
        self.wfile.write( bytes( svg_file, "UTF-8") )
      
      else:
        self.send_response(404)
        self.end_headers()
        self.wfile.write(bytes("404: not found", "UTF-8"))

home_page = """
<html>
  <head>
    <title> File Upload </title>
  </head>
  <body>
    <h1> File Upload </h1>
    <form action="molecule" enctype="multipart/form-data" method="post">
        <p>
            <input type="file" id="sdf_file" name="filename"/>
        </p>
        <p>
            <input type="submit" value="Upload"/>
        </p>
    </form>
  </body>
</html>
""";

httpd = HTTPServer(('localhost', int(sys.argv[1])), MyHandler) #use port 57980
httpd.serve_forever()
