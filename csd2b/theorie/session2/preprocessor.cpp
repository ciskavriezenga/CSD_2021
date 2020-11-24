#include <iostream>

#define SOM 4+5


int main()
{

#ifdef SOM
  std::cout << 3*SOM << std::endl;
#else
  std::cout << "SOM bestaat niet" << std::endl;
#endif

  return 0;
} 

