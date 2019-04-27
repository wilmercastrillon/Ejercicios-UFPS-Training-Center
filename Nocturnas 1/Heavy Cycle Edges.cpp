#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int padre[1010];
struct union_find{
	int tam = 0;

	void iniciar(int n){
		for (int i = 0; i < n; i++)
			padre[i] = i;
		tam = n;
	}

	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
	}

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		padre[x] = y;
	}

	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

typedef pair<int, int> ii;
#define mpiii(a, b, c) iii(a, ii(b, c))
//insertar: grafo.push_back(mpiii(7, 0, 1))

typedef pair<int, ii> iii;//peso, origen y destino
vector<iii> listaInc;//lista de incidencia
union_find arbol;
vector<int> res;

int kruskal(vector<iii> lista, int nodos, union_find &uf){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos);
	int acum = 0, ejes = 0, n = nodos - 1;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			//if(ejes == n) return acum;
		}else{
			res.push_back(lista[i].first);
		}
	}
	return -1;
}

int main(){
    int n, m, a, b, c;

    while(scanf("%d %d", &n, &m), n){
        listaInc.clear();
        arbol.iniciar(n+1);
        res.clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            listaInc.push_back(mpiii(c,a,b));
        }

        kruskal(listaInc, n, arbol);
        sort(res.begin(), res.end());
        if(res.size()) printf("%d", res[0]);
        else{
            printf("forest\n");
            continue;
        }
        for(int i = 1; i < res.size(); i++){
            printf(" %d", res[i]);
        }
        printf("\n");
    }

	return 0;
}


