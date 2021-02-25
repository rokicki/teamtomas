#include <iostream>
#include <map>
#include <string>
#include <istream>
#include <vector>
using namespace std ;
extern int D, I, S, V, F ;
struct street {
   int b, e, len, id, uses ;
   string name ;
} ;
using streetp = struct street *;
struct path {
   vector<streetp> itin ;
   int len ;
} ;
struct schedentry {
   streetp str ;
   int dur ;
} ;
struct intersection {
   vector<streetp> in, out ;
   vector<schedentry> sched ;
} ;
extern vector<intersection> intersections ;
extern vector<street> streets ;
extern vector<path> paths ;
extern int verbose ;
extern map<string, streetp> atlas ;
extern int readdata(istream &is) ;
extern int readsched(istream &is) ;
extern void error(const char *s) ;
extern int runsim() ;
extern void writesched() ;
