#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso - destino
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii> cola;
vector<bool> vis;

void vecinos(vvii &lista, int nodo){
    vis[nodo] = true;
    for(int i = 0; i < lista[nodo].size(); i++){
        ii par = lista[nodo][i];//peso - destino
        if(!vis[par.second])
            cola.push(ii(-par.first, -par.second));
    }
}

int prim(vvii &lista, int n){
    vis.assign(n + 1, false);
    vecinos(lista, 1);
    int acum = 0; ii par;

    while(cola.size()){
        par = cola.top(); cola.pop();
        if(vis[-par.second]) continue;
        acum += -par.first;
        vecinos(lista, -par.second);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) return inf;
    }
    return acum;
}

map<string, int> mapa;

int main(){
    cin.tie(NULL);
    int n, m, z;

    while(cin >> n >> m){
        if(n == 0) break;
        vvii grafo(n + 1);

        string s, x, y;
        int con = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            mapa[s] = ++con;
        }

        for(int i = 0; i < m; i++){
            cin >> x >> y >> z;
            grafo[mapa[x]].push_back(ii(z, mapa[y]));
            grafo[mapa[y]].push_back(ii(z, mapa[x]));
        }

        cin >> s;
        //cola.push(mapa[s]);

        int may = prim(grafo, n);
        if(may == inf) cout << "Impossible\n";
        else cout << may << '\n';
    }

    return 0;
}


