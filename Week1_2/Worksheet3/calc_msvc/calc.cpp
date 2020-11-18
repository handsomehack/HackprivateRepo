// calc.cpp --------------------------------
#include <sstream>
#include <iostream>
// adder.h -----------------------------------
// The following two lines prevent adder.h from being included
// more than once in any source (.cpp) file. If this were to happen
// it would cause problems in the compile process but it is difficult to
// prevent manually in large projects. These #ifndef, #define and #endif
// commands for an "include guard" and are types of compiler directive.
// The include guard contains an ID for this file "MATHSLIB_ADDER_H", this is
// arbitrary but must be unique within the project.
#ifndef MATHSLIB_ADDER_H
#define MATHSLIB_ADDER_H
// prototype for our function
int add( int a, int b );
#endif
// /adder.h --------------------------------------

int main( int argc, char *argv[]) {
int a, b, c;
if(argc != 3) return 1;
std::string sa( argv[1] );
std::string sb( argv[2] );
std::stringstream ssa( sa );
std::stringstream ssb( sb );
ssa >> a;
ssb >> b;
c = add( a, b );
std::cout << c;
return 0;
}
// /calc.cpp ---------------------------------