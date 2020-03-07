//Program pobiera dwie liczby od użytkownika i wyświetla ich NWD
//Jes tutaj przyklad jak sprawdzac czy w buforze cin sa poprawne dane
//i jak sie zabezpieczyc aby nie wpasc w nieskonczona petle gdy uzytkownik
//poda nieodpowiednie dane na przyklad wpisze litere do zmiennej int
#include <iostream>
#include <string>
#include <stdlib.h>//atoi()
#include <limits>//numeric_limits template
using namespace std;

int NWD(int a, int b) {
    return b==0 ? a : NWD(b, a % b);
}
int main()
{
    char z = 'd';
    do
    {
        int x = 0;
        int y = 0;
        cin.sync();

        cout << "Podaj liczbe x :";
        //gdy bufor napotka problem flaga bitfalse zostanie ustawiona
        //wtedy (cin>>x)==false czyli !(cin>>x)==true i petla while sie wykona
        while(!(cin >> x)){
            cout<<"to nie jest liczba! Podaj liczbe: ";
            cin.clear();
            cin.ignore();
        }

        cout << "Podaj liczbe y :";
        while(!(cin>>y)){
            cout<<"to nie jest liczba! Podaj liczbe: ";
            cin.clear();
            cin.ignore();
        };    
            
        cout << "NWD liczb "<<x<<" i "<<y<<" wynosi : "<<NWD(x,y)<<endl;
        cout<<"Aby kontynuowac wcisnij dowolny klawisz; k - koniec"<<endl;
        cin>>z;

    } while((z!='k'));
    return 0;
}
