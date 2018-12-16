#include <bits/stdc++.h>

using namespace std;

set<string> ss;

int main(){
    cin.tie(NULL);

    int t, n;
    cin >> t;
    string s;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            transform(s.begin(), s.end(),s.begin(), ::toupper);
            ss.insert(s);
        }

        set<string>::iterator it;
        vector<string> vec;
        for(it = ss.begin(); it != ss.end(); it++){
            vec.push_back(*it);
        }
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << '\n';
        }
    }

    return 0;
}
