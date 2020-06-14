#include "./polymorphism.h"
#include <iostream>
#include <memory>

struct destruct {
  int a = 0;
  std::string s;
};

int main(int argc, char *argv[]) {

  destruct mystr;

  auto [x, y] = mystr;

  std::unique_ptr<int> p1(new int(5));
  // std::unique_ptr<int> p2 = p1; // Compile error.
  std::unique_ptr<int> p3 =
      std::move(p1); // Transfers ownership. p3 now owns the memory and p1 is
                     // set to nullptr.

  Rectangle rect;
  Triangle trgl;
  Polygon *ppoly1 = &rect;
  Polygon *ppoly2 = &trgl;
  ppoly1->set_values(4, 5);
  ppoly2->set_values(4, 5);
  std::cout << rect.getArea() << '\n';
  std::cout << trgl.getArea() << '\n';
  return 0;
}
