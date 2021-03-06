#include "world.h"
int D, I, S, V, F ;
int verbose = 1 ;
vector<street> streets ;
vector<path> paths ;
vector<intersection> intersections ;
map<string, streetp> atlas ;
int readdata(istream &is) {
   is >> D >> I >> S >> V >> F ;
   streets.resize(S) ;
   int sc = 0 ;
   for (auto &s : streets) {
      is >> s.b >> s.e >> s.name >> s.len ;
      s.uses = 0 ;
      s.id = sc++ ;
   }
   for (auto &s : streets)
      atlas[s.name] = &s ;
   intersections.resize(I) ;
   for (auto &s : streets) {
      intersections[s.b].out.push_back(&s) ;
      intersections[s.e].in.push_back(&s) ;
   }
   paths.resize(V) ;
   for (auto &v : paths) {
      int sz ;
      string s ;
      is >> sz ;
      int sum = 0 ;
      for (int i=0; i<sz; i++) {
         is >> s ;
         v.itin.push_back(atlas[s]) ;
         sum += atlas[s]->len ;
      }
      v.len = sum ;
      if (verbose)
         cout << "Path has len " << v.len << " slop " << D-v.len << endl ;
      if (v.len <= D) {
         for (int i=1; i<sz; i++)
            v.itin[i]->uses++ ;
      }
   }
   return 1 ;
}
