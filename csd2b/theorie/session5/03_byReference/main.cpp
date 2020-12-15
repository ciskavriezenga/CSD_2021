#include <iostream>


int add(int x, int y) {
  return x + y;
}

void addPointer(int* x, int y) {
  *x += y;
}

void addByReference(int& x, int y) {
  x += y;
}



int main() {
  int a = 8;
  int b = 10;

  // -------- add function with a return --------
  std::cout << "\nadd: " << add(a, b);

  // -------- add function with a pointer --------
  /*
   * NOTE: with pointers we can do 'things'
   * we might not want to allow
   */
  //float c = (float)a;
  //addPointer((int*) &c, b);

  int c = a;
  addPointer(&c, b);
  std::cout << "\naddPointer: " << c;

  // -------- add function, pass by reference --------
  int d = a;
  addByReference(d, b);
  std::cout << "\naddByReference: " << d;

  std::cout << "\n";
}
