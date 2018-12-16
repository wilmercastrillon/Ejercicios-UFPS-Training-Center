#include <bits/stdc++.h>
using namespace std;

double a, vo, d, x;

double dis2(double t){//posicion despues de correr t
    return (a*t*t)/2;
}

double tiempo(){//tiemp que tardara en alcanzarlo
    return (sqrt(2.0*a*d + vo*vo) + vo)/a;
}


int main() {
    int t;
    scanf("%d", &t);
    //printf("%lld\n", sum(50000000));
    while(t--){
        scanf("%lf %lf %lf %lf", &a, &vo, &d, &x);

        //printf("demora %.5f en alcanzarlo\n", tiempo());
        double aux = tiempo();
        if(dis2(aux) > x) printf("No alcanzara :(\n");
        else printf("%.2f\n", aux);
    }
	return 0;
}
