#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;

char tab[110][110];
int vis[110][110], fil, col;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col || tab[f][c]=='*');
}

void bfs(int fini, int cini){
    queue<ii> cola;
    queue<int> colap;
    colap.push(1);
    cola.push(ii(fini, cini));
    ii par;
    int f, c, auxf, auxc, paso;

    while(cola.size()){
        par = cola.front();  cola.pop();
        paso = colap.front(); colap.pop();
        f = par.first;
        c = par.second;
        //printf("%d %d paso %d\n", f, c, paso);
        if(paso > vis[f][c]) continue;
        vis[f][c] = paso;
        //printf("sigue\n");

        for(int i = 0; i < 4; i++){
            auxf = f + mf[i];
            auxc = c + mc[i];
            if(val(auxf, auxc) && paso+1<vis[auxf][auxc]){
                vis[auxf][auxc] = paso+1;
                cola.push(ii(auxf, auxc));
                colap.push(paso+1);
            }
        }
    }
}

void pintar(int dir, int f, int c){
    f += mf[dir];
    c += mc[dir];
    //printf("dir %d\n", dir);

    while(val(f, c) && tab[f][c] == '.' || tab[f][c] == 'S' || tab[f][c] == 'E'){
        vis[f][c] = -1;
        //printf("pintamos %d %d, %c ????\n", f, c, tab[f][c]);
        f += mf[dir];
        c += mc[dir];
    }
}

int main(){
    int t, fe, ce, fs, cs;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &fil, &col);
        memset(vis, 5436, sizeof(vis));

        for(int i = 0; i < fil; i++){
            scanf("%s", &tab[i]);
        }

        for(int i = 0; i < fil; i++){
            for(int j = 0; j < col; j++){
                if(tab[i][j] == '^') pintar(0, i, j);
                else if(tab[i][j] == '>') pintar(1, i, j);
                else if(tab[i][j] == 'v') pintar(2, i, j);
                else if(tab[i][j] == '<') pintar(3, i, j);
                else if(tab[i][j] == 'E'){
                    fe = i;  ce = j;
                }else  if(tab[i][j] == 'S'){
                    fs = i;  cs = j;
                }
            }
        }

        bfs(fe, ce);
        int res = vis[fs][cs];
        if(res > 0  && res < 1000000000){
            printf("%d\n", res-1);
        }else{
            printf("Despertara gritando\n");
        }
    }

    return 0;
}


