#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
  int a[5] = {91, 8, 13, 24, 55};
  int *wsk = a;
  cout<<a<<endl;
  cout<<a+1<<endl;
  cout<<*a<<endl;  
  cout<<"&wsk = "<<&wsk<<endl;
  for (int i = -2; i<10; i++){
    cout<<"wsk+"<<i<<" = "<<wsk+i<<", *wsk+"<<i<<" = "<<*(wsk+i)<<endl;
  }

  struct daneST{
    int liczba;
    char znak;
  };

  daneST dane;
  dane.liczba = 342;
  dane.znak = 'a';
  daneST *p_dane = &dane;

  cout<<(*p_dane).liczba<<endl;
  cout<<p_dane->znak<<endl;

  //sztywna tablica sztywnych tablic sztywnych tablic:)
  int const A=3, B=4, C=9;
  int ar[A][B][C] = {0,}
  //ZSS
  int (*)
  return 0;
}
