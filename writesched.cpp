/*
 *   Read a schedule into the intersections object.
 */
#include "world.h"
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
      set<int> seen ;
      for (auto &s : inter.sched) {
         if (seen.find(s.str->id) != seen.end())
            continue ;
         seen.insert(s.str->id) ;
         cout << s.str->name << " " << cnts[s.str->id] << endl ;
      }
   }
}
