#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
    fstream outfile;
    outfile.open("liczbyLosowe.txt", ios::app | ios::out);
    srand( time( NULL ) );//losowe ziarno
    if (outfile.is_open()){
    for (int i=1; i<=800; i++) {//petla losujaca liczby i zapisujaca je do pliku
        int k = 1+rand()%6;
        outfile << k << endl;
        }
    }
    outfile.seekp(0, ios::end);//przesuwa wskaźnik na koniec pliku
    streampos e = outfile.tellp();//odczyt pozycji w pliku
    printf("rozmiar : %li", (e));//wypisanie pozycji w pliku
    outfile.close();
    cout<<"\nzakonczono zapis do pliku \n"<<endl;
    cout<<"teraz bede czystal z pliku \n"<<endl;
    outfile.open("liczbyLosowe.txt", ios::app | ios::in);
    char bufor[501];
    outfile.getline(bufor, 500);
    int suma = 0;//sumujemy liczby w buforze, tak dla zabawy
    for(int i=0; i<=500; i++) {
      cout<<bufor[i];
      suma = suma + bufor[i];
    }
    cout<<endl<<suma<<endl;
    cout<<"\nodczytano linie, koniec"<<endl;
    system("pause");
    return 0;
}
