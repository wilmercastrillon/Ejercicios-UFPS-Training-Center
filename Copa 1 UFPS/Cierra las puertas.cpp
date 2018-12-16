#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n;
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%lld", &n);
        if(n == 0){
            printf("\n");
            continue;
        }
        vector<int> v;
        for(lli i = 1; i*i <= n; i++){
            v.push_back(i*i);
        }

        printf("%d", v[0]);
        for(int i = 1; i < v.size(); i++)
            printf(" %d", v[i]);
        printf("\n");
    }
    return 0;
}


