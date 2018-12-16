#include <iostream>

using namespace std;

int main(){
    int n, m, t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        if(n > m){
            cout << "perdimos\n";
        }else if(n < m){
            cout << "ganamos\n";
        }else{
            cout << "casi ganamos\n";
        }
    }
    return 0;
}
