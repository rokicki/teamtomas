#include <iostream>
#include <string>
#include <vector>
using namespace std ;
extern int D, I, S, V, F ;
struct street {
   int b, e, len ;
   string name ;
} ;
using streetp = struct street *;
using path = vector<streetp> ;
extern vector<street> streets ;
extern vector<path> paths ;
