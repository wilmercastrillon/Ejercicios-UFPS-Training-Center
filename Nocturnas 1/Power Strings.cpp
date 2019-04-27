#include <bits/stdc++.h>

using namespace std;
int bordes[1000];

void preCalcular(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

int kmp(string cad, string subcad){
    int i = 0, j = 0, cant = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            //printf("%s esta en el indice %d de la cadena: %s\n",
            //       subcad.c_str(), i - j, cad.c_str());
            cant++;
            j = bordes[j];
        }
    }
    return cant;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s1, s2;
    while(true){
        cin >> s1;
        if(s1[0] == '.') break;
        s2 = s1+s1;
        preCalcular(s1);
        cout << kmp(s2, s1)-1 << '\n';
    }
    return 0;
}



