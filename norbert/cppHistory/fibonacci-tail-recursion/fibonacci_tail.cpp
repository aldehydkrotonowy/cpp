#include <iostream>
using namespace std;

int fibonacci(int n, int acc, int b);

int main(){
	fibonacci(10, 1, 0);
	return(0);
}
int fibonacci(int n, int acc, int b){
	if (n == 0) return acc;
	cout << n << ": " << acc << endl;
	return fibonacci(n-1, acc+b, acc);
}