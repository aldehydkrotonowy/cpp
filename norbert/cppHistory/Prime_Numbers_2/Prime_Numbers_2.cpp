#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;
vector<int> prime_number_list;
int list_size = 0;

bool isPrime(int N);

int main(){
    string FileName;
    ofstream fout;
    cout<<"----Witam---"<<endl;
    //cout<<"Podaj liczbe : ";
    //cin>>Number;
    cout<<"Podaj nazwe pliku : ";
    cin>>FileName;
    FileName +=".txt";
    fout.open(FileName.c_str(), ios::out);
    if(fout.fail()){
        cerr<<"Problem przy otwieraniu"<<endl;
        assert(fout.good());//jesli nieprawda to program stop
    }
    for (int i=2; list_size<500000; i++) {
        int thisNumber = i;
        list_size = prime_number_list.size();
        if(isPrime(thisNumber)){
            prime_number_list.push_back(thisNumber);
            fout.width(10);
            fout<<thisNumber;
            if((list_size+1)%10 == 0){
                fout<<endl;
            }
        }
    }
    fout.flush();
    fout.close();
    cout<<"----koniec";
    return 0;
}
bool isPrime(int N){
    int thisFactor;
    int maxFactor = sqrt(N);
    bool RetValue = true;
    for (int i = 0; i < list_size; ++i){
        thisFactor = prime_number_list[i];
        if(thisFactor > maxFactor){
            break;
        }
        if((N%thisFactor) == 0){

            RetValue = false;
            break;
        }
    }
    return RetValue;
}
