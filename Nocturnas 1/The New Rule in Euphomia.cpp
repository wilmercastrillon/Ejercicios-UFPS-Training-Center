#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>
#define forr(i, m) for(int i = 0; i < m; ++i)

using namespace std;
typedef long long int lli;

int m = 1000010, primo[1000020];
vector<lli> p;  int lim = sqrt(m)+1;
map<lli, int> mapa;
int memo[1000020];

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}


int main(){
    criba();
    int n, caso = 0;

    while(scanf("%d", &n), n){
        int con = 0;
        for(int i = 0; p[i] < n; i++){
            int q = lower_bound(p.begin()+i, p.end(), n-p[i]) - p.begin();
            if((p[i]+p[q]) > n) q--;
            if(q == -1) continue;
            //cout << "n= " << i << " tenemos buscar " << (n-p[i]) << " primo# " << q << " = " << p[q] << " | suma: " << (p[i]+p[q]) << endl;
            if(q-i <= 0) break;
            con += (q-i);
        }

        printf("Case %d: %d\n", ++caso, con);
    }
    return 0;
}


