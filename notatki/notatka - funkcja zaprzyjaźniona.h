//funkcje zaprzyjaźnione cpp
#include <iostream>
using namespace std;

class Zakres;

class Punkt {
	int liczba;
	friend void isInside(Punkt *p, Zakres *z);
	public:
		Punkt(int liczba=0) : liczba(liczba);
}

class Zakres {
	int lewy, prawy;
	friend void isInside(Punkt *p, Zkres *z);
	public:
		Zakres(int lewy=0, int prawy=0) : lewy(lewy), prawy(prawy);
}

void isInside (Punkt *p, Zakres *z) {
	if (p->liczba >= z->lewy && p->liczba <=z->prawy)
		cout<<"w zakresie"<<endl;
	else
		cout<<"poza zakresem"<<endl;
}
int main() {
	Punkt pp(4);
	Zakres z1(1,9), z2(9,23);
	isInside(&p, &z1);
	isInside(&p, &z2);
	return 0;
}