// na podstawie youtube: www.youtube.comwatchv=8mR6xds9IU0
#include <iostream>
class A {
	
public://three types of constructors
	
	A():number(0){
		std::cout << "default constructor" << std::endl; //default constructor
	}							
	A(int n):number(n){
		std::cout << "convert constructor" << std::endl; //convert constructor 
	}						
	A(const A& a) : number(a.number){
		std::cout << "copy constructor" << std::endl; //copy constructor
	}	
private:
	int number;
};

int main(){
	A a;		//default
	A b(7);	//convert
	A c(b);	//copy
	A d = b; //copy
}