#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, f;
    while(1){
        cin >> n >> k >> f;
        if(n == 0) break;
        int res;
        if(f > k){
            res = (n - f) + k;
        }else{
            res = k - f;
        }
        cout << res << '\n';
    }

    return 0;
}


