#include "world.h"
#include <fstream>
/*
 *   Read an input file and generate an output schedule that simply
 *   cycles each intersection.
 */
int main(int argc, char *argv[]) {
   verbose = 0 ;
   fstream is(argv[1]) ;
   readdata(is) ;
   int cnt = 0 ;
   for (int i=0; i<I; i++)
      if (intersections[i].in.size())
         cnt++ ;
   cout << cnt << endl ;
   for (int i=0; i<I; i++) {
      if (intersections[i].in.size() == 0)
         continue ;
      cout << i << endl ;
      cout << intersections[i].in.size() << endl ;
      for (int j=0; j<(int)intersections[i].in.size(); j++) {
         cout << intersections[i].in[j]->name << " " << 1 << endl ;
      }
   }
}

