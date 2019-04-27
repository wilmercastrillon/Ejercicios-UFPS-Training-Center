#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef unsigned long long int lli;
typedef __int128 ulli;

ulli x, y, aux;

bool f(ulli n){
    return (((n*(n+1)*(2*n+1))/6)+x) > (y+((n*(n+1))>>1));
}

ulli busqueda_binaria(ulli men, ulli may){
    ulli epsilon = 1, med = 0, n1, n2;

    while(may-men > epsilon){
        med = (may+men)>>1;
        if(f(med))
            may = med;
        else
            men = med;

    }
    return may;
}

int main(){
    ulli ini;

    lli in1, in2, res;
    while(cin >> in1 >> in2){
        x = (ulli) in1;
        y = (ulli) in2;
        ini = 1000000000;

        res = (lli)busqueda_binaria(0, ini);
        cout << res << '\n';
    }
}

