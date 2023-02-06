#include <iostream>

class Animal {};
class Dog : public Animal {};

void walk(Animal &a) {
  std::cout << "an animal is walking" << std::endl;
}

void walk(Dog &a) {
  std::cout << "dog is walking" << std::endl;
}

void f(Animal &a) {
  walk(a);
}

int main() {
  Dog d;
  f(d);
  return 0;
}

