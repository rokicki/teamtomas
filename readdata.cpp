#include <iostream>
#include <string>
#include <vector>
using namespace std ;
int D, I, S, V, F ;
struct street {
   int b, e, len ;
   string name ;
} ;
using path = vector<string> ;
vector<street> streets ;
vector<path> paths ;
int main() {
   cin >> D >> I >> S >> V >> F ;
   streets.resize(S) ;
   for (auto &s : streets)
      cin >> s.b >> s.e >> s.name >> s.len ;
   paths.resize(V) ;
   for (auto &v : paths) {
      int sz ;
      string s ;
      cin >> sz ;
      for (int i=0; i<sz; i++) {
         cin >> s ;
         v.push_back(s) ;
      }
   }
   cout << "Parsed!" << endl ;
}
