#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include <algorithm>
#define foor(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int c[110], t[110], ll[110], n;

void pre(){
    int ant = 0, l = n+2;
    foor(i, l){
        ll[i] += ant;
        ant = ll[i];
        //printf("tab %d\n", ll[i]);
    }
}

int query(int i, int j){
    if(j < i) swap(i, j);
    return ll[j] - ll[i];
}

int ffff(int i, int j){
    if(j < i) swap(i, j);
    int acum = 0;
    for(int k = i+1; k <= j; k++){
        acum += ll[k];
    }
    return acum;
}

int main(){//No terminado
    int actual;

    while(cin >> n){
        foor(i, n) cin >> c[i];
        foor(i, n) cin >> t[i];
        foor(i, n) cin >> ll[i];
        //pre();

        cin >> actual;
        actual--;

        int caja = 1000000000, tiempo = 1000000000;
        int camina = 0, aux;
        for(int i = 0; i < actual ; i++){
            aux = c[i]*t[i] + ffff(i, actual);
            //printf("1demora %d con caminar %d | todo %d\n", c[i]*t[i],ffff(i, actual), aux);
            if(aux < tiempo){
                tiempo = aux;
                caja = i;
            }else if(aux == tiempo){
                caja = min(caja, i);
            }
        }
        for(int i = actual; i < n;i++){
            aux = c[i]*t[i] + ffff(i, actual);
            //printf("2demora %d con caminar %d | todo %d\n", c[i]*t[i],ffff(i, actual), aux );
            if(aux < tiempo){
                tiempo = aux;
                caja = i;
            }else if(aux == tiempo){
                caja = min(caja, i);
            }
        }

        cout << (caja+1) << " " << tiempo << "\n";
    }
}





