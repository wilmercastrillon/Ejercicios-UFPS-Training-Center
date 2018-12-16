#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

double p, k, n;

double res(){
    double q = 8.0*k + 8.0*n + 4.0*p*p + 1.0;
    double w = (sqrt(q) + 2.0*p-1.0)/2.0;
    return ceil(w);
}

lli sum(lli d){
    return (d*(d+1))/2;
}

bool f(lli d){
    return ((lli) p*d + n) < ((lli) sum(d) + k);
}

int main() {
    //printf("%lld\n", sum(50000000));
    while(scanf("%lf %lf %lf", &p, &k, &n) != EOF){
        lli aux = (lli) res();
        for(; f(aux); aux--);
        printf("%lld\n", aux+1);
    }
	return 0;
}
