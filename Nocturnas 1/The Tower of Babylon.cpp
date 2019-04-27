#include <iostream>
#include <string.h>
#include <vector>
#define forr(i, n) for(int i = 0; i < n; ++i)

using namespace std;
typedef vector<int> vi;

int bloque[100][3], memo[100], n, l;
vector<vi> vec;

void add(int pos, int x, int y, int z){
    bloque[pos][0] = x;
    bloque[pos][1] = y;
    bloque[pos][2] = z;
}

bool val(int pos1, int pos2){ //pos2 encima de pos1
    return (bloque[pos2][0] < bloque[pos1][0] &&
            bloque[pos2][1] < bloque[pos1][1]) ||
            (bloque[pos2][0] < bloque[pos1][1] &&
            bloque[pos2][1] < bloque[pos1][0]);
}

int dp(int ant){
    //printf("llega a %d\n", ant);
    if(memo[ant] != -1) return memo[ant];

    int ans = 0, q;
    for(int i = 0; i < vec[ant].size(); ++i){
        q = vec[ant][i];
        ans = max(ans, bloque[q][2] + dp(q));
        /*printf("\t ## no sirve poner %d %d %d abajo de %d %d %d\n",
                   bloque[ant][0],bloque[ant][1],bloque[ant][2],
                   bloque[i][0],bloque[i][1],bloque[i][2])*/
    }
    //printf("se devuelve con ans = %d\n", ans);
    return memo[ant] = ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y, z, caso = 0;
    while(cin >> n){
        if(!n) break;
        l = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            add(l, x, y, z);  l++;
            add(l, z, x, y);  l++;
            add(l, y, z, x);  l++;
        }

        vec.assign(l, vi(0));
        for(int i = 0; i < l; ++i){
            forr(j, l){
                if(val(i, j)){
                    vec[i].push_back(j);//los que se pueden poner arriba
                }
            }
        }

        int res = 0;
            memset(memo, -1, sizeof(memo));
        for(int i = 0; i < l; ++i){
            res = max(res, dp(i) + bloque[i][2]);
        }
        cout << "Case " << ++caso << ": maximum height = " << res << '\n';
    }
}


