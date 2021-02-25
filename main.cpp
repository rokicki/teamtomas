#include "world.h"
#include <fstream>
int main(int argc, char *argv[]) {
   verbose = 0 ;
   fstream is(argv[1]) ;
   readdata(is) ;
   is.close() ;
   if (argc > 2) {
      fstream is2(argv[2]) ;
      readsched(is2) ;
      is2.close() ;
      int sc = runsim() ;
      cout << "Final score " << sc << endl ;
   }
}

