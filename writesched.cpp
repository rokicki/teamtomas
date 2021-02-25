/*
 *   Read a schedule into the intersections object.
 */
#include "world.h"
#include <math.h>
#include <set>
void writesched() {
   int nsched = 0 ;
   for (int i=0; i<I; i++)
      if (intersections[i].sched.size())
         nsched++ ;
   cout << nsched << endl ;
   for (int i=0; i<I; i++) {
      auto &inter = intersections[i] ;
      if (inter.sched.size() == 0)
         continue ;
      map<int, int> cnts ;
      for (auto &s : inter.sched)
         cnts[s.str->id] += 1 ;
      cout << i << endl ;
      cout << cnts.size() << endl ;
      vector<int> p ;
      for (auto &s : cnts)
         p.push_back(s.first) ;
      for (int j=0; j<(int)p.size(); j++) {
         int k = (int)(p.size()*drand48()) ;
         swap(p[k], p[j]) ;
      }
      for (auto &pp : p) {
         cout << streets[pp].name << " " << (int)(1+(sqrt(cnts[pp]))) << endl ;
      }
   }
}
