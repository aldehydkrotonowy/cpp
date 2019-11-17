/*
    PROBLEM 1
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <iostream>

void multiple3or5();


using namespace std;
int main(){
    cout<<"multiples of 3 and 5 below 1000"<<endl;
    multiple3or5();
    return(0);
}

void multiple3or5(){
    int sum = 0;
    for (int i=0; i<=1000; i++){
        if((i%3==0) | (i%5==0)){
            cout<<"I found number : "<<i<<endl;
            sum = sum + i;
            cout<<"suma to ::: "<<sum<<endl;
        }
    }
}
