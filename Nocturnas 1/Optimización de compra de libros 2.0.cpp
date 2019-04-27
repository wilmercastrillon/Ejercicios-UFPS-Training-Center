#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

int ganancia[101];
int peso[101];

int N, cap1, cap2, cap3;
int memo[101][151][151][151];//objetos-cap1-cap2-cap3

int mochila(int obj, int cap1, int cap2, int cap3){//Top-Down
    if(obj >= N) return 0;
    if(memo[obj][cap1][cap2][cap3] != -1) return memo[obj][cap1][cap2][cap3];

    int ans = mochila(obj+1, cap1, cap2, cap3);

    if(peso[obj] <= cap1)
        ans = max(ans, ganancia[obj]+mochila(obj+1,cap1-peso[obj],cap2,cap3));

    if(peso[obj] <= cap2)
        ans = max(ans, ganancia[obj]+mochila(obj+1,cap1,cap2-peso[obj],cap3));

    if(peso[obj] <= cap3)
        ans = max(ans, ganancia[obj]+mochila(obj+1,cap1,cap2,cap3-peso[obj]));

    return memo[obj][cap1][cap2][cap3] = ans;
}

int knapsack() {
    for(int i = 0; i < N; ++i){
       if(peso[i] + j <= cap1){
            memo[i][j+peso[i]][k][l] ganancia[i];
        }
    }

    for(int i = 0; i < N; ++i)
    for(int j = 0; j < cap1; ++j)
    for(int k = 0; k < cap2; ++k)
    for(int l = 0; l < cap3; ++l){
        if(peso[i] + j <= cap1){
            memo[i][j+peso[i]][k][l] = max(memo[i][j+peso[i]][k][l], memo[i][j][k][l]+ganancia[i]);
        }
        if(peso[i] + k <= cap2){
            memo[i][j][k+peso[i]][l] = max(memo[i][j][k+peso[i]][l], memo[i][j][k][l]+ganancia[i]);
        }
        if(peso[i] + l <= cap3){
            memo[i][j][k][l+peso[i]] = max(memo[i][j][k][l+peso[i]], memo[i][j][k][l]+ganancia[i]);
        }
    }
    return memo[N-1][cap1][cap2][cap3];
}

int main(){//NO TERMINADO
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(cin >> N >> cap1 >> cap2 >> cap3){
        memset(memo, 0, sizeof(memo));

        for(int i = 0; i < N; ++i){
            cin >> peso[i];
        }
        for(int i = 0; i < N; ++i){
            cin >> ganancia[i];
        }

        cout << knapsack() << '\n';
    }
}



