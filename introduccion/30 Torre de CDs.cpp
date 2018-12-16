#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int t, c, x;
    scanf("%d", &t);

    while(t--){
        stack<int> pila;
        scanf("%d", &c);
        for(int i = 0; i < c; i++){
            scanf("%d", &x);
            if(x){
                pila.push(x);
            }else{
                printf("%d\n", pila.top());
                pila.pop();
            }
        }
    }
    return 0;
}

