#include <iostream>

using namespace std;

int main()
{
    const int n = 100;
    bool array[n+1] = {0};

    for(int i=2; i*i<n; i++) {
        if(array[i] == true)
            continue;
        for (int j=2*i; j<=n; j+=i) {
            array[j] = true;
        }
    }
    cout<<"Prime nubers in range [2,n] :"<<endl;
    int k = 0;
    for (int i=2; i<=n; i++){
        if (array[i] == false)
            cout<<i<<" ";
    }
    return 0;
}
