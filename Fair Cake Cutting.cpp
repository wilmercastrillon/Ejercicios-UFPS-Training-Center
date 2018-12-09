#include <stdio.h>

using namespace std;

int main(){
    double a, b, c, res;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        res = c/(a/b);
        printf("%.0f\n", res);
    }
    return 0;
}
