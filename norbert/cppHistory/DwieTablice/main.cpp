#include <iostream>

using namespace std;
void fillTab_A(int tab[], int sizeTab_A){
    for(int i=0; i<=sizeTab_A; i++){
        tab[i]=1*i;
    }
}
void writeA(int tab[], int sizeTab_A) {
    for(int i=0;i<=sizeTab_A; i++){
        cout<<" "<<tab[i]<<" ";
    }
}
void fillTab_B(int tab[]) {
    int sizeTab_B = (sizeof(tab)/sizeof(int));
    cout<<"sizeTab_B in fillTab_B is : "<<sizeTab_B<<endl;
    for(int j=0; j<=sizeTab_B; j++) {
        tab[j]=2*j;
    }
}
void writeB(int tab[]) {
    int sizeTab_B = (sizeof(tab)/sizeof(int));
    cout<<"sizeTab_B in writeB is : "<<sizeTab_B<<endl;
    for(int j=0; j<=sizeTab_B; j++){
        cout<<" "<<tab[j]<<" ";
    }
}
int main()
{
    int tableA[10];
    int tableB[20];

    int sizeTab_A = (sizeof(tableA)/sizeof(int));

    fillTab_A(tableA, sizeTab_A);
    cout<<"tableA: "<<endl;
    writeA(tableA, sizeTab_A);

    cout<<endl<<"--------------------------"<<endl;

    fillTab_B(tableB);
    cout<<"tableB: "<<endl;//from this point sizeTab_B is equal 40 instead of 20. Why?
    writeB(tableB);
    return 0;
}

