#include <iostream>
using namespace std;

int factorial(int n, int acc){
	if (n == 0) return acc;
	return factorial(n-1, n*acc);
}
int factorial_wrapper(int n){
	return factorial(n, 1);
}

int main(){
	int n;
	cout << "Factorial_tail: podaj n" << endl;
	cin >> n;
	cout << factorial_wrapper(n) << endl;
	
	return(0);
}
