#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    int t, n, m, x;
    scanf("%d", &t);

    while(t--){
        n = m = 0;
        for(int i = 0; i < 6; i++){
            scanf("%d", &x);
            n = n | (x<<i);
        }
        for(int i = 0; i < 6; i++){
            scanf("%d", &x);
            m = m | (x<<i);
        }

        if((n^m) == 63){
            printf("COMPATIBLE\n");
        }else{
            printf("INCOMPATIBLE\n");
        }
    }
    return 0;
}

