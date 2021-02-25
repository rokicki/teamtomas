#include "world.h"
#include <fstream>
int main(int argc, char *argv[]) {
   fstream is(argv[1]) ;
   readdata(is) ;
}

