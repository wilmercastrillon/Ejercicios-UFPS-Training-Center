#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

vi padre;

struct union_find{
	int tam = 0;

	void iniciar(int n){
		for (int i = 0; i <= n; i++){
			padre.push_back(i);
		}
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

int kruskal(vector<iii> lista, int nodos, union_find &uf){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos);
	int acum = 0, ejes = 0, n = nodos - 1, may = 0;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			may = max(may, lista[i].first);
			if(ejes == n) return may;
		}
	}
	return -1;
}

int main(){
    int n, m, x, y, z;

    while(scanf("%d %d", &n, &m), n){
        listaInc.clear();
        padre.clear();
        arbol.iniciar(n+1);

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            listaInc.push_back(mpiii(z, x, y));
        }

        int res = kruskal(listaInc, n, arbol);
        if(res == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", res);
    }

	return 0;
}


