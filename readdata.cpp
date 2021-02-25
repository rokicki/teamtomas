#include "world.h"
#include <map>
int D, I, S, V, F ;
vector<street> streets ;
vector<path> paths ;
int readdata(istream &is) {
   map<string, streetp> atlas ;
   is >> D >> I >> S >> V >> F ;
   streets.resize(S) ;
   for (auto &s : streets)
      is >> s.b >> s.e >> s.name >> s.len ;
   for (auto &s : streets)
      atlas[s.name] = &s ;
   paths.resize(V) ;
   for (auto &v : paths) {
      int sz ;
      string s ;
      is >> sz ;
      for (int i=0; i<sz; i++) {
         is >> s ;
         v.push_back(atlas[s]) ;
      }
   }
   return 1 ;
}
