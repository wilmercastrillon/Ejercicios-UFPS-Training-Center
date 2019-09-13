#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> ii;

struct team{
    int ej;
    string nombre;

    team(string s){
        nombre = s;
        ej = 0;
    }
};


vector<team> vt;
vector<ii> event;//tiempo, equipo
map<string, int> mapa;

bool cmp(team &a, team &b){
    if(a.ej != b.ej) return a.ej > b.ej;
    return a.nombre < b.nombre;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int casos, t, p, m, minuto, idx, pro;
    cin >> casos;

    for(int i = 0; i < casos; i++){
        cin >> t >> p >> m;
        vt.clear();
        mapa.clear();
        event.clear();

        string x, res;
        int con = 0;
        for(int j = 0; j < t; j++){
            cin >> x;
            mapa[x] = con++;
            vt.push_back(team(x));
        }

        for(int j = 0; j < m; j++){
            cin >> minuto >> x >> pro >> res;
            if(res == "ACCEPTED"){
                event.push_back(ii(minuto,x));
            }
        }
        sort(event.begin(),event.end());

        for(int j = 0; j < event.size(); j++){
            minuto = event[j].first;
            x = event[j].second;
            for(idx = 0; idx < vt.size(); ++idx)
                if(vt[idx].nombre == x) break;
            vt[idx].ej++;
            sort(vt.begin(), vt.end(), cmp);
            cout << vt[0].nombre << '\n';
        }
    }

    return 0;
}
