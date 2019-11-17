
/* 
    ten programik wyrósł przy próbie tworzenia algorytmu sortowania bombelkowego
    jest zbyt przekombinowany i nie rozumiem na razie tego schematu template.
    Program dziąła a kompilować należy z opcjąć -std=C++11
    Na razie wklejam to tutaj, może się przydać.
*/
#include <iostream>
#include <array>
using namespace std;

void sortowanie_bombelkowe(int tab[], int size){
    cout<<size<<endl;
}

template <typename T> void readArray(const T& data) {
  for (const auto& element : data)
    cout << element;
}


int main(){
    //mój kod nie działa, 
    //  cannot convert 'std::array<int, 200u>' to 'int*' for argument '1' to 'void sortowanie_bombelkowe(int*, int)'
    //na razie nie rozumiem dlaczego
    array <int,200> a{0};//opcja kompilatora -std=c++11
    int s = a.size();
    //sortowanie_bombelkowe(a, s);

    //ten kod działa
    //skopiowane z : http://stackoverflow.com/questions/36759177/cant-convert-stdarray-to-int
    array<int, 5> data1 = { 1, 2, 3, 4, 5};
    readArray(data1);
    return(0);
}