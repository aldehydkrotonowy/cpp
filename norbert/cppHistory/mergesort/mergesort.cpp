#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 30

using namespace std;

void fill_array(int t[], int size){
    srand(time(NULL));//initialization
    for (int i=0; i<=size; i++){
        t[i] = rand()/10;        
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<=size; i++){
        cout<<"liczba "<<i<<" to : "<<arr[i]<<endl;
    }
}

//s - start, m - middle, e - end
void merge(int arr[], int s, int m, int e){
  //cout<<"merge params ("<<s<<", "<<m<<", "<<e<<")"<<endl;
  //copy elements to helper array h[N]
  int h[N];
  for(int i=s; i<=e; i++){
    h[i]=arr[i];
  }
  int i = s, j = m+1, k = s; 
  while (i<=m && j<=e){
    if(h[i] < h[j]) {
      arr[k++] = h[i++];
    }
    else{
      arr[k++] = h[j++];
    };
  };
  //if first half have more elements then second half
  while(i<=m){
    arr[k++]=h[i++];
  }
  //if second half have more elements then first one
  while(j<=e){
    arr[k++]=h[j++];
  }
};
void mergesort(int arr[], int s, int e){

  //cout<<"collign mergesort with params ("<<s<<", "<<e<<")"<<endl;
  if(s < e){
    //the same as (s+e)/2, but avoids overflow for large s and e.    
    int m = s+(e-s)/2;
    mergesort(arr, s, m);    
    mergesort(arr, m+1, e); 
    merge(arr, s, m, e);
  };
};


int main(){
  int array[N];
  int size = (sizeof(array)/sizeof(array[0]));
  fill_array(array, size-1);
  cout<<"array before sort"<<endl;
  printArray(array, size-1);
  cout<<endl<<"sorting..."<<endl;
  mergesort(array, 0, size-1);
  cout<<endl<<"array after sort"<<endl;
  printArray(array, size-1);
  return(0);
}
