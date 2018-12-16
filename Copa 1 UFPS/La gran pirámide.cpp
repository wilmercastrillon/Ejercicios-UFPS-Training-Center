#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);

    long long res, t, n;
    cin >> t;

    while(t--){
        cin >> n;
        res = (n*(4*n*n - 1))/3;

        cout << res << '\n';
    }


	return 0;
}


