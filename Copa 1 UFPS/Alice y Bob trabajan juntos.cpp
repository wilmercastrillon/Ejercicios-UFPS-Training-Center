#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii grafo;
vector<int> vis;

vi dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, inf);
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();//peso, nodo
        cola.pop();
        peso = -par.first;
        nodo = par.second;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            aux = dis[nodo] + par2.first;
            if(dis[par2.second] > aux){
                cola.push(ii(-aux, par2.second));
            }
        }
    }

    return dis;
}

void dfs(int n, int c){
    vis[n] = c;
    for(int i = 0; i < grafo[n].size(); i++){
        if(!vis[grafo[n][i].second]) dfs(grafo[n][i].second, c);
    }
}

int con[300];

int main(){
    int n, m;
    int t, x, y, z;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        grafo.assign(n+1, vii(0));

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo[x].push_back(ii(z, y));
            grafo[y].push_back(ii(z, x));
        }

        vis.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            if(!vis[i]) dfs(i, i);
            con[vis[i]]++;
        }

        int may = 1000000;
        for(int i = 1; i <= n; i++){
            if(con[i] != 0 && con[i] > 1) may = min(may, con[vis[i]]);
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
            if(con[i] == may){
                vi q = dijkstra(grafo, i, n+1);
                for(int j = 0; j < q.size(); j++){
                    if(q[j] != inf) res = max(res, q[j]);
                }
            }
        }

        printf("%d\n", res);
    }

    return 0;
}


