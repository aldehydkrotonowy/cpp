#include <iostream>

using namespace std;

template <class T> class mypare {
  T a, b;

public:
  mypare(T first, T second) {
    a = first;
    b = second;
  }
  T getMax();
};

template <class T> T mypare<T>::getMax() {
  T retval;
  retval = a > b ? a : b;
  return retval;
}

// fibonacci template version
template <size_t n> struct fib;
template <> struct fib<1> { const static auto value = 1; };
template <> struct fib<0> { const static auto value = 1; };

template <size_t n> struct fib {
  const static auto value = fib<n - 1>::value + fib<n - 2>::value;
};

int main() {
  mypare<int> myobject(100, 200);
  cout << myobject.getMax();
  return 0;
}