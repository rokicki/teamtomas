#include "world.h"
#include <map>
int D, I, S, V, F ;
vector<street> streets ;
vector<path> paths ;
int main() {
   map<string, streetp> atlas ;
   cin >> D >> I >> S >> V >> F ;
   streets.resize(S) ;
   for (auto &s : streets)
      cin >> s.b >> s.e >> s.name >> s.len ;
   for (auto &s : streets)
      atlas[s.name] = &s ;
   paths.resize(V) ;
   for (auto &v : paths) {
      int sz ;
      string s ;
      cin >> sz ;
      for (int i=0; i<sz; i++) {
         cin >> s ;
         v.push_back(atlas[s]) ;
      }
   }
   cout << "Parsed!" << endl ;
}
