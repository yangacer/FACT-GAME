#include <cstdlib>
#include <cassert>
#include "core.hpp"	

int 
main(int argc, char* argv[]) { 

  AsWind::CApp theApp; 

  int extCode = theApp.OnExecute(); 

  return extCode;
}
