#include <iostream>
#include <fstream>
using namespace std;
int main(){

    char napis[20];
    string line;
    long start, stop;
    //---------------------------------------------
    ofstream out_file("example.txt");
    out_file<<"this string will be in example.txt. \n";
    out_file<<"another string";
    out_file.close();
    ifstream in_file("example.txt");
    if(!in_file.is_open())
        cout<<"====UNABLE TO OPEN FILE===="<<endl;
    else {
        cout<<"====OPENING FILE==== \n";
        while(getline(in_file, line))
            cout<<line<<endl;
        cout<<"====closing file===="<<endl;
        in_file.close();
    }
    cout<<"======================"<<endl;
    //---------------------------------------------
    ifstream in_file2("word list.txt");

    if(in_file2.is_open()){
        while(getline(in_file2, line))
            cout<<line<<endl;
    }
    else cout<<"I can't open the file"<<endl;
    //---------------------------------------------
    start = in_file2.tellg();//odczyt pozycji wskaŸnika strumieniu get
    in_file2.seekg (0, ios::end);//ustawienie pozycji wskaŸnika
    stop = in_file2.tellg();
    in_file2.close();
    cout<<"dlugosc pliku wynosi "<<(stop-start)<<endl;
    return 0;
}
