#include <bits/stdc++.h>
using namespace std;

int main(){
    int ar[10];
    ar[0] = 5;
    ar[1] = 30;
    ar[2] = 155;
    ar[3] = 780;
    ar[4] = 3905;
    cin.tie(NULL);
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        int i;
        for(i = 0; i < 5; i++){
            if(n <= ar[i]) break;
        }
        if(i == 0) cout << "leyenda\n";
        else if(i == 1) cout << "platino\n";
        else if(i == 2) cout << "oro\n";
        else if(i == 3) cout << "plata\n";
        else if(i == 4)  cout << "bronce\n";
    }

    return 0;
}

