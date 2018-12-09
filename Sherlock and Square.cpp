#include <stdio.h>

using namespace std;
typedef long long int ll;

ll mulmod (ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b > 0){
        if (b&1) x = (x+y) % c;
        y = (y<<1) % c;
        b >>= 1;
    }
    return x % c;
}

ll expmod (ll b, ll e, ll m){//O(log b)
    if(!e) return 1;
    ll q = expmod(b,e>>1,m); q = mulmod(q,q,m);
    return (e&1)? mulmod(b,q,m): q;
}

int main(){
    ll n, x;
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", (((expmod(2, n, 1000000007) - 1)<<1) + 4) % 1000000007);
    }

    return 0;
}


