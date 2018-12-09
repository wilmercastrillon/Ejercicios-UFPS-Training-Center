#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    string ss;
    while(cin >> ss){
        for(int i = 0; i < ss.size(); i++){
            cout << (int) ss[i];
        }
        cout << '\n';
    }

    return 0;
}
