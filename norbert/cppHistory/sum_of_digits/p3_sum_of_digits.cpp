/*
 * Program calculates sum of digits from 1 to n
 * S(10^d-1) = S(10^[d-1]-1)+10^[d-1]*45
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int sum_of_digits(double n, int d, double a[]){
  if (n < 10) return (n*(n+1))/2;  
  double msd = floor(n / pow(10, d-1));  
  double next_n = n-msd*pow(10,d-1);
  return msd*a[d-1]+pow(10, d-1)*(((msd-1)*msd)/2)+msd*(n-msd*pow(10,d-1)+1)+sum_of_digits(next_n, d-1, a);
  }
int main(){
  int d, i;
  double a[10];
  double r, number;
  cout<<"************************************************"<<endl;
  cout<<"*                                              *"<<endl;
  cout<<"* Program calculates sum of digits from 1 to n *"<<endl;
  cout<<"*                                              *"<<endl;
  cout<<"************************************************"<<endl<<endl;
  do{
    d = 0;//cleaning
    //enter number and if it is greater than zero accept them.
    do{
      cout<<"Give me some positive number. Enter '0 (zero)' to stop."<<endl;
      cin>>number;      
      if(number<0) {cout<<"Number must be greater than zero. Try again"<<endl;}
      if(number>=63175000){cout<<"Entered number is too big."<<endl;}
    }while(number<0 || number>63175000);
    if (number==0) {break;} //If user enter zero --> STOP PROGRAM
    r = number;
    //compute exponent+1
    while(r>0){
      r = floor(r / 10);    
      d++;
    }    
    //calculate partial sums S(9), S(99), S(999), ...
    for (i = 1; i<=d; i++){
      a[i]=i*(pow(10,i-1)*45);
    }
    cout<<"-----"<<endl;
    cout<<"Sum of all digits in numbers from 1 to "<<number<<" is ";
    cout<<sum_of_digits(number, d, a)<<endl<<endl;
  }while(!(number == 0));
  cout<<"PROGRAM STOP"<<endl;
  return(0);
}