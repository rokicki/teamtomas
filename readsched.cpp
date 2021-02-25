/*
 *   Read a schedule into the intersections object.
 */
#include "world.h"
int readsched(istream &is) {
   int nsched ;
   is >> nsched ;
   for (int i=0; i<nsched; i++) {
      int id, n ;
      is >> id >> n ;
      intersection &inter = intersections[id] ;
      for (int i=0; i<n; i++) {
         string s ;
         int len ;
         is >> s >> len ;
         streetp str = atlas[s] ;
         inter.sched.push_back({str, len}) ;
      }
   }
   return 1 ;
}
