#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;

char tab[210][210][210], cad[300];
int vis[210][210][210], fil, col, alt;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c, int a){
    return !(f<0 || f>=fil || c<0 || c>=col || a<0 || a>=alt || tab[f][c][a]=='#');
}

void bfs(int fini, int cini, int aini){
    if(!val(fini, cini, aini)) return;
    queue<ii> cola1;//f, c
    queue<ii> cola2;//a, p
    cola1.push(ii(fini, cini));
    cola2.push(ii(aini, 1));
    ii par1, par2;
    int f, c, a, auxf, auxc, auxa, paso;

    while(cola1.size()){
        par1 = cola1.front(); cola1.pop();
        par2 = cola2.front(); cola2.pop();
        f = par1.first;
        c = par1.second;
        a = par2.first;
        paso = par2.second;

        if(paso > vis[f][c][a]) continue;
        vis[f][c][a] = paso;

        for(int i = 0; i < 4; i++){
            auxf = f + mf[i];
            auxc = c + mc[i];
            auxa = a;
            if(val(auxf, auxc, auxa) && paso+1<vis[auxf][auxc][auxa]){
                vis[auxf][auxc][auxa] = paso+1;
                cola1.push(ii(auxf, auxc));
                cola2.push(ii(auxa, paso+1));
            }
        }
        if(tab[f][c][a] == '-'){
            if(val(f, c, a+1) && paso+1<vis[f][c][a+1] && tab[f][c][a+1] == '-'){
                vis[f][c][auxa] = paso+1;
                cola1.push(ii(f, c));
                cola2.push(ii(a+1, paso+1));
            }
            if(val(f, c, a-1) && paso+1<vis[f][c][a-1] && tab[f][c][a-1] == '-'){
                vis[f][c][auxa] = paso+1;
                cola1.push(ii(f, c));
                cola2.push(ii(a-1, paso+1));
            }
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    //cin.tie(NULL);
    int fe, ce, ae, fs, cs, as;

    while(scanf("%d %d %d", &fil, &col, &alt) != EOF){
        if(fil == 0 && col == 0 && alt == 0) break;
        memset(vis, 5436, sizeof(vis));
        fe = ce = ae = fs = cs = as = -1;

        for(int i = 0; i < alt; i++){
            for(int j = 0; j < fil; j++){
                scanf("%s", &cad);
                for(int k = 0; k < col; k++){
                    tab[j][k][i] = cad[k];
                    if(tab[j][k][i] == 'S'){
                        fs = j;
                        cs = k;
                        as = i;
                    }
                    if(tab[j][k][i] == 'E'){
                        fe = j;
                        ce = k;
                        ae = i;
                    }
                }
                //printf("piso %d | fila %d\n", i, j);
            }
            //printf("leyo pis %d\n", i);
        }
        //printf("lee\n");

        bfs(fs, cs, as);
        int res = vis[fe][ce][ae];
        if(res < 1000000000){
            res--;
            cout << res << '\n';
        }else{
            cout << "-1\n";
        }
    }

    return 0;
}

