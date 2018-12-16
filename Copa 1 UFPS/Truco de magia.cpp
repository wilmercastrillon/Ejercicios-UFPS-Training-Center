#include <bits/stdc++.h>
using namespace std;

bool matriz[35][7];

void pre(){
    memset(matriz, 0, sizeof(matriz));
}

int main(){
    int t;
    string i1, i2, i3, i4, i5;

    while(cin >> i1 >> i2>> i3>>i4>>i5){
        int n = 0;
        if(i1 == "SI") n |= (1<<0);
        if(i2 == "SI") n |= (1<<1);
        if(i3 == "SI") n |= (1<<2);
        if(i4 == "SI") n |= (1<<3);
        if(i5 == "SI") n |= (1<<4);
        cout << "abracadabra, tu numero es: "<< n << '\n';
    }

    return 0;
}




