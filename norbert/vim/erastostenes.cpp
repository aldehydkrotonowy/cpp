#include <iostream>
#include <cstdio>
using namespace std;
int sito(int*, unsigned int);
int main(int argc, char* argv[]){
    int size;
    int *arr;
    cout<<"number of arguments: "<<argc<<endl;
    if (argc>=2){
        for (int i=0;i<argc;i++){
            cout<<"arg nr"<<i<<" is "<<argv[i]<<endl;
        }
        if (sscanf(argv[1], "%i", &size)==1){
            cout<<size<<endl;
            arr = new int[size]();
        }else{
            cout<<"i couldn't convert";
        }
    }else{
        cout<<"give me the upper bond"<<endl;
        cin>>size;
        arr = new int[size]();
    }
	cout<<"Starting algorithm"<<endl;
	sito(arr, size);
	cout<<"process end"<<endl;
	cout<<"This are results:"<<endl;
	for (int i=2;i<size;i++){
		if (!arr[i]) cout<<i<<" ";
		if (i%10==0) cout<<endl; 
	}
	return 0;
}
	
int sito (int *arr, unsigned int n){
	for (int i=2; i*i<=n; i++){
		if (!arr[i]) {
			for (int j=i*i;j<=n;j+=i) arr[j]=true;
		}	
	}
}
