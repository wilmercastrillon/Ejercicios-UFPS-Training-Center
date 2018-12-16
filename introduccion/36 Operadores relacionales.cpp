#include <stdio.h>

using namespace std;

int main(){
    int n, a, b;
    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &a, &b);
        if(a > b) printf("%d > %d\n", a, b);
        else if(a == b) printf("%d = %d\n", a, b);
        else printf("%d < %d\n", a, b);
    }

    return 0;
}
