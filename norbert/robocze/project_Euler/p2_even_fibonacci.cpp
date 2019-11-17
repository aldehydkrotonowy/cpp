/*
    PROBLEM 2
    Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
    1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
    By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>
using namespace std;

unsigned long long int fibonacci(unsigned long long int n, unsigned long long jalonge int f1, unsigned long long int f2, unsigned long long int sum);
void helper(unsigned long long int n);

int main(){ kd adkkdjfkjasdkjfkasd fka sdfk asdkfj 
    
    helper(97);
    return(0);
}

void helper(unsigned long long int n){
    fibonacci(n, 0, 1, 0);
}

unsigned long long int fibonacci(unsigned long long int n, unsigned long long int f1, unsigned long long int f2, unsigned long long int sum){
        if (f2%2 == 0){    
            sum += f2;
            cout << f2 <<" parzyste | "<<"suma wynosi "<< sum <<endl;
        }else{
            cout << f2 << endl;
        }   
    if (n == 1) return sum;
    return fibonacci(n-1, f2, f1+f2, sum);


}

/*
ostatnie kilka wierszy z wydruku:
2880067194370816120 parzyste | suma wynosi 3770056902373173214
4660046610375530309
7540113804746346429
12200160415121876738 parzyste | suma wynosi 15970217317495049952 ---ostatnia prawidłowa suma przed przekroczeniem zakresu unsigned long long
1293530146158671551
13493690561280548289
14787220707439219840 parzyste | suma wynosi 12310693951224718176 ---suma się już przekręciła i jest mniejsza niz poprzednia; f2 jest ostatnią prawidłową wartością przed przekroczeniem
zakresu unsigned long long int
9834167195010216513 --- f2 jest juz nieprawidłowe - przekroczono zakres
*/
