#include <iostream>
#include <vector>
#include <string.h>
#define foor(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int k;
string s;

int mulmod(int a, int b, int c){//(a*b) % c
    int x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

int expmod (int b, int e, int m){//O(log b)
	if(!e) return 1;
	int q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

bool div(){
    int mod = (expmod(10, s.size()-1, k) * (s[0]-'0')) % k;
    for(int i = 1; i < s.size(); ++i){
        mod += (expmod(10, s.size()-(i+1), k) * (s[i]-'0')) % k;
        mod = mod % k;
    }
    return mod == 0;
}

bool divsum(){
    int mod = 0;
    for(int i = 0; i < s.size(); ++i){
        mod = (mod + (s[i]-'0')) % k;
    }
    return mod == 0;
}

bool divmult(){
    int mod = 1;
    for(int i = 0; i < s.size(); ++i){
        mod = (mod * (s[i]-'0')) % k;
    }
    return mod == 0;
}

int main(){
    int con = 0;
    while(cin >> k >> s){
        con = 0;
        if(div()){
            cout << "SI ";
            con++;
        }else{
            cout << "NO ";
            con--;
        }
        if(divsum()){
            cout << "SI ";
            con++;
        }else{
            cout << "NO ";
            con--;
        }

        if(divmult()){
            cout << "SI";
            con++;
        }else{
            cout << "NO";
            con--;
        }

        if(con == 3) cout << " PERFECTO\n";
        else if(con == -3) cout << " ABURRIDO\n";
        else cout << "\n";
    }
}




