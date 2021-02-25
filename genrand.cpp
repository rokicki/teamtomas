#include "world.h"
#include <cstdlib>
#include <fstream>
#include <sys/time.h>
/*
 *   Read an input file and generate an output schedule that simply
 *   cycles each intersection.
 */
int main(int argc, char *argv[]) {
   srand48(time(0)) ;
   verbose = 0 ;
   fstream is(argv[1]) ;
   readdata(is) ;
   int cnt = 0 ;
   for (int i=0; i<I; i++)
      if (intersections[i].in.size())
         cnt++ ;
   cout << cnt << endl ;
   vector<int> p ;
   for (int i=0; i<I; i++) {
      if (intersections[i].in.size() == 0)
         continue ;
      cout << i << endl ;
      cout << intersections[i].in.size() << endl ;
      p.clear() ;
      for (int j=0; j<(int)intersections[i].in.size(); j++)
         p.push_back(j) ;
      for (int j=0; j<(int)intersections[i].in.size(); j++) {
         int k = j + (int)((intersections[i].in.size()-j)*drand48()) ;
         swap(p[j], p[k]) ;
      }
      for (int j=0; j<(int)intersections[i].in.size(); j++) {
         cout << intersections[i].in[p[j]]->name << " " << 1 << endl ;
      }
   }
}
