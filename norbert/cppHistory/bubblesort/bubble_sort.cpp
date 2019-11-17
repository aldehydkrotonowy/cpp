#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fill_table(int t[], int size){
    srand(time(NULL));
    for (int i=0; i<=size; i++){
        t[i] = rand();        
    }
}
void printArray(int tab[], int size){
    for(int i=0; i<=size; i++){
        cout<<"liczba "<<i<<" to : "<<tab[i]<<endl;
    }
}
void bubble_sort_v1_naive(int tab[], int size){
    int temp, i, swap;   
    do{
        i = 0; 
        swap = 0;        
        do{
            if (tab[i+1] < tab[i]){
                temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
                swap = 1;                
            }
            i++;
        }while(i!=(size));
    }while(swap!=0);
}
void bubble_sort_v2_asc(int tab[], int n){
    bool swapped;
    int temp;
    for(int i = 0; i<=n-1; i++){
        swapped = false;
        for(int j=0; j<=n-i-1; j++){
            if(tab[j+1] < tab[j]){
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                swapped = true;
            }            
        }
        if(swapped == false){
            break;
        }
    }
}
void bubble_sort_v2_desc(int tab[], int n){
    int temp;
    bool swapFlag;
    for(int i = 0; i<=n-1; i++){
        swapFlag = false;
        for(int j = 0; j<=n-i-1; j++){
            if(tab[j+1] > tab[j]){
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                swapFlag = true;
            }
        }
        if(swapFlag == false){ break; }
    }
}
int main(){
    int s = 10;
    int a[s];
    int size = (sizeof(a)/sizeof(*a));
    cout<<"table size is :"<<size<<endl;
    cout<<"I am filling array with "<<size+1<<" random numbers"<<endl;    
    fill_table(a, s);
    printArray(a, s);
    cout<<"I am sorting in ascending order."<<endl;
    bubble_sort_v2_asc(a, s);
    cout<<"Array after ascending sorting:"<<endl;
    printArray(a, s);
    cout<<"I am sorting in descending order"<<endl;
    bubble_sort_v2_desc(a, s);
    cout<<"Array after descending sorting:"<<endl;
    printArray(a, s);
    return(0);
}

