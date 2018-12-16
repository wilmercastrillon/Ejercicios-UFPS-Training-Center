#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

set<int> pos;

int main(){
    int n, q, x, y;

    while(scanf("%d %d", &n, &q) != EOF){
        pos.clear();
        for(int i = 0; i < q; i++){
            scanf("%d %d", &x, &y);
            if(x == 0) pos.insert(y);
            else{
                set<int>::iterator it2;
                int con = 0;
                for(it2 = pos.begin(); it2 != pos.end(); it2++){
                    if(*it2 > y+con) break;
                    con++;
                }
                if(y + con > n) printf("-1\n");
                else printf("%d\n", y + con);
            }
        }


        //printf("%d\n", res);
    }

    return 0;
}


