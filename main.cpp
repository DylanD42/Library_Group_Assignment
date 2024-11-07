#include "library.h"
#include <iostream>

using namespace std;

int main() {
  Library PML;
  
  PML.read_from_file("imput.txt");
  PML.print();

  return 0;
}

