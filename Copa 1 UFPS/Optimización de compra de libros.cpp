#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

int ganancia[1010], peso[1010];

int N;
int memo[1010][1010];//objetos-capacidad

int dp(int cap, int n) {
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++){
            if(i == 0 || j == 0) memo[i][j] = 0;
            else if(peso[i - 1] <= j)
                memo[i][j] = max(memo[i - 1][j],
                            ganancia[i - 1] + memo[i - 1][j - peso[i - 1]]);
            else
                memo[i][j] = memo[i - 1][j];
        }
    }
    return memo[n][cap];
}

int main(){
    int t, cap, n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &cap, &n);
        int posgan = 0, pospeso = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &k);
            for(int i = 0; i < k; i++){
                scanf("%d", &peso[pospeso]);
                pospeso++;
            }
            for(int i = 0; i < k; i++){
                scanf("%d", &ganancia[posgan]);
                posgan++;
            }
        }

        N = pospeso;
        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(cap, N));
    }
    return 0;
}


