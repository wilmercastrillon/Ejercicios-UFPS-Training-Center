#include <iostream>
#include <math.h>

using namespace std;

int gcd_ex (int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_ex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main(){//No terminado
    int n, m, sol, x, y, res;

    while(cin >> n >> m >> sol){
        res = gcd_ex(n, m, x, y);
        //cout << "gcd = " << res << ", x = " << x << ", y = " << y << endl;
        //if(sol % res) printf("no tiene solucion\n");

        int x0 = (sol/res)*x;
        int y0 = (sol/res)*y;
        double lim1 = x0*1.0/(m/res*-1.0);
        double lim2 = y0*1.0/(n/res);
        int aux1, aux2;

        //printf("x = %d + %d n\n", x0, m/res);
        //printf("y = %d - %d n\n", y0, n/res);
        //printf("%d %d | %.5f < n < %.5f\n", x0, y0, lim1, lim2);
        int men = min(ceil(lim1), ceil(lim2)), may = max(floor(lim1), floor(lim2));
        int mayor = 0, ans = 0;
        //printf("soluciones:\n");

        for(int i = may; i >= men; i--){
            aux1 = (int) ((double) x0 + (m/res)*i);
            aux2 = (int) ((double) y0 - (n/res)*i);

            if(aux1 >= 0 && aux2 >= 0){
                if(aux1+aux2 > mayor){
                    mayor = aux1+aux2;
                    ans = n*aux1 + m*aux2;
                }
                //printf("%d %d %d\n", i, aux1, aux2);
            }
        }

        if(ans < sol) printf("%d %d\n",mayor, sol - ans);
        else printf("%d\n", mayor);
    }
}


