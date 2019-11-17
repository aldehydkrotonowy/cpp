#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string FileName;
    string tresc;
    ofstream MyFile;
    //pobieranie danych
    cout<<"Enter the name of the file. \n";
    cin>>FileName;
    FileName+= ".txt";
    cout<<"Enter text: ";
    cin>>tresc;
    cout<<"The number of characters entered : "<<tresc.length()<<endl;
    //zapisywanie do pliku
    MyFile.open(FileName.c_str(), ios::app);
    if (MyFile.is_open() == true){
        cout<<"Access to file"<<endl;
        MyFile.write(&tresc[0], tresc.length());
        MyFile.close();}
    else {
        cout<<"File error."<<endl;
    }
    ifstream streamIn;
    cout<<"I am reading file..."<<endl;
    streamIn.open(FileName.c_str());
    if (streamIn.is_open()){
        while(getline(streamIn, tresc)){
            cout<<tresc<<endl;
            cout<<"read : "<<tresc.length()<<" characters"<<endl;
        }

        streamIn.close();
    }
    return 0;
}
