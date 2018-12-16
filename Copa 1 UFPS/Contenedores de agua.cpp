#include <bits/stdc++.h>

using namespace std;

int cont(long long k){
    int con = 0;
    long long j = 1;
    for(long long i = 0; i < 63; i++){
        if(k & j) con++;
        j <<= 1;
        //cout << k << " , " << i << endl;
    }
    return con;
}

int main(){
    cin.tie(NULL);
    long long t, n, k, h, res;
    cin >> t;

    while(t--){
        cin >> n >> k >> h;

        res = cont(n)*h + n*k;
        //cout << "bits " << cont(n) << endl;
        cout << res << '\n';
    }

	return 0;
}


