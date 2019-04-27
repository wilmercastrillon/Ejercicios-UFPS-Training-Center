#include <bits/stdc++.h>
#define forr(i, t) for(int i = 0; i < t; ++i)

using namespace std;
double eps = 1e-5;

struct punto{
    double x, y;

    punto(){ x = y = 0.0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }

    bool operator < (punto p) const{//para poder usar sort
        if(fabs(x - p.x) > eps) return x < p.x;
        return y < p.y;
    }
};


struct linea{
    double a, b, c;
    punto p1, p2;

    linea(double _a, double _b, double _c){
        a = _a;  b = _b;  c = _c;
    }
    linea(){
        a = 0;  b = 0;  c = 0;
    }
    linea(punto _p1, punto _p2){
        p1 = punto(_p1.x, _p1.y);
        p2 = punto(_p2.x, _p2.y);
        if(fabs(p1.x - p2.x) < eps){
            a = 1.0;  b = 0.0;  c = -p1.x;
        }else{
            a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
            b = 1.0;
            c = -(double)(a*p1.x) - p1.y;
        }
    }
};

bool paralelas(linea l1, linea l2){
    return (fabs(l1.a-l2.a)<eps) && (fabs(l1.b-l2.b)<eps);
}
bool iguales(linea l1, linea l2){
    return paralelas(l1, l2) && fabs(l1.c-l2.c)<eps;
}
bool interseccion(linea l1, linea l2, punto &p){
    if(paralelas(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

bool inside(double a, double b, double c, double d, punto p){
    bool pos = true;
    pos = pos && ((fabs(b-p.y) < eps || fabs(d-p.y) < eps) || (b <= p.y && p.y <= d));
    pos = pos && ((fabs(a-p.x) < eps || fabs(c-p.x) < eps) || (a <= p.x && p.x <= c));
    return pos;
}

int main(){//No terminado
    double a, b, c, d;
    int t;
    scanf("%d", &t);
    linea rect[4];
    punto p;

    for(int i = 0; i < t; i++){
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        //printf("lee %.5f %.5f %.5f %.5f\n", a, b, c, d);
        linea l1(punto(a, b), punto(c, d));

        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        rect[0] = linea(punto(a, b), punto(c, b));
        rect[1] = linea(punto(c, b), punto(c, d));
        rect[2] = linea(punto(c, d), punto(a, d));
        rect[3] = linea(punto(a, d), punto(a, b));

        bool res = false, pos;
        double aux;
        forr(j, 4){
            pos = false;
            if(interseccion(l1, rect[j], p)){
                if(fabs(b-p.y) < eps || fabs(d-p.y) < eps)
                    pos = true;
                if(b <= p.y && p.y <= d)
                    pos = true;

                if(pos){
                    if(fabs(a-p.x) < eps || fabs(c-p.x) < eps)
                        res = true;
                    if(a <= p.x && p.x <= c)
                        res = true;
                    //printf("cruza con j = %d | %.5f %.5f | y = %.5f\n", j, p.x, p.y, findy(l1, p.x));
                }
                //break;
            }
        }

        res = res || (inside(a,b,c,d,l1.p1)&&inside(a,b,c,d,l1.p2));
        printf("%s\n", (res)? "T":"F");
    }

    return 0;
}


