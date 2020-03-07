#include <iostream>

using namespace std;

template <class T>
class mypare
{
  T a, b;

public:
  mypare(T first, T second)
  {
    a = first;
    b = second;
  }
  T getMax();
};

template <class T>
T mypare<T>::getMax()
{
  T retval;
  retval = a > b ? a : b;
  return retval;
}

int main()
{
  mypare<int> myobject(100, 200);
  cout << myobject.getMax();
  return 0;
}