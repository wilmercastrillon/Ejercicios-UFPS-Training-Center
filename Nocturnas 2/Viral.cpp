#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include <algorithm>
#define foor(i, n) for(int i = 0; i < n; ++i)

using namespace std;

string s, aux;

string quitar(){
    int l = s.size()-2;
    string res = "";

    foor(i, s.size()){
        if(i < l){
            if((s[i] == s[i+1]) && (s[i] == s[i+2])){
                i += 2;
                continue;
            }
        }
        res.push_back(s[i]);
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(cin >> aux){
        do{
            s = aux;
            //cout << "s = " << s << endl;
            aux = quitar();
        }while(aux.size() != s.size());
        //cout << "s = " << aux << endl;

        if(aux.size() == 0){
            cout << "SI\n";
        }else cout << "NO\n";
    }
}





