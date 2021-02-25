#include <iostream>
#include <string>
#include <istream>
#include <vector>
using namespace std ;
extern int D, I, S, V, F ;
struct street {
   int b, e, len ;
   string name ;
} ;
using streetp = struct street *;
struct path {
   vector<streetp> itin ;
   int len ;
} ;
struct intersection {
   vector<streetp> in, out ;
} ;
extern vector<intersection> intersections ;
extern vector<street> streets ;
extern vector<path> paths ;
extern int readdata(istream &is) ;
extern int verbose ;
extern void error(const char *s) ;
