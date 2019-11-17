#include <stdio.h>
#include <stdlib.h>
typedef struct intVector v;
struct intVector {
    int x;
    int y;
    int z;
    };
int main()
{

    intVector v1 = {2,5,17};
    intVector v2 = {5,1,46};
    intVector wynik;
    wynik = {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
    printf("Wynik dodawania dwóch wektorow wynois :  %d\n", wynik);

    return 0;
}
