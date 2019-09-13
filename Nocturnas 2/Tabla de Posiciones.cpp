#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include <algorithm>
#define foor(i, n) for(int i = 0; i < n; ++i)

using namespace std;

struct t{
    string nombre;
    int first,res,pen;
};
t team[20];

int can, sol[26];
string s, s2;
map<string, int> mapa;

bool cmp(t &a, t &b){
    if(a.res != b.res) return a.res > b.res;
    if(a.pen != b.pen) return a.pen < b.pen;
    if(a.first != b.first) return a.first > b.first;
    return a.nombre < b.nombre;
}

int main(){
    int t, k, caso = 0;
    cin >> t;

    while(t--){
        mapa.clear();
        cin >> can;
        int idx = 0;
        memset(sol, 0, sizeof(sol));

        getchar();
        foor(i, can){
            getline(cin, s);
            mapa[s] = ++idx;
            team[idx].nombre = s;
            team[idx].first = 0;
            team[idx].res = 0;
            team[idx].pen = 0;
        }
        //printf("################\n");

        cin >> k;
        getchar();
        int tiempo, pro, idx2;
        string ver;

        foor(i, k){
            //printf("---\n");
            getline(cin, s2);
            stringstream ss(s2);

            vector<string> vec;
            string aux, nombre = "";
            while(ss >> aux){
                vec.push_back(aux);
            }

            tiempo = atoi(vec[0].c_str());
            for(int i = 1; i < vec.size()-2; i++){
                nombre = nombre + " ";
                nombre = nombre + vec[i];
            }
            nombre = nombre.substr(1);
            ver = vec[vec.size()-2];
            pro = vec[vec.size()-1][0]-'A';
            idx2 = mapa[nombre];

            if(ver == "ACC"){
                team[idx2].pen += tiempo;
                if(sol[pro] == 0) team[idx2].first++;
                team[idx2].res++;
                sol[pro]++;
            }else{
                team[idx2].pen += 20;
            }
        }
        sort(team+1, team+can+1, cmp);
        cout << "Competencia " << (++caso) << ":\n";
        foor(i, can){
            cout << (i+1) << ". " << team[i+1].nombre << " " << team[i+1].res << " " << team[i+1].pen << " " << team[i+1].first << "\n";
        }
        if(t > 0) cout << "\n";
        //printf("-----------------------------");
    }
}





