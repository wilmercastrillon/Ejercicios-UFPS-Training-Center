#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    int n, b, q, w;
    scanf("%d", &n);

    while(n--){
        scanf("%d", &b);
        queue<int> buses;

        while(b--){
            scanf("%d %d", &q, &w);
            if(q == 1){
                buses.push(w);
            }else{
                printf("%d\n", buses.front());
                buses.pop();
            }
        }
    }
    return 0;
}
