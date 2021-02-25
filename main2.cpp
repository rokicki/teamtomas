#include "world.h"
#include <fstream>
int main(int argc, char *argv[]) {
   verbose = 0 ;
   fstream is(argv[1]) ;
   readdata(is) ;
   is.close() ;
   runsim() ;
   writesched() ;
}
