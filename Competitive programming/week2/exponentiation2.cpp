#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = 1e9+7;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a%m;
        a = a * a%m;
        b >>= 1;
    }
    return res;
}

long long binpow2(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a%(m-1);
        a = a * a%(m-1);
        b >>= 1;
    }
    return res;
}

int main() {
	ll n,a,b,c;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		b = binpow2(b,c);
        //cout<<b<<endl;
		cout<<binpow(a,b)<<endl;
	}
}// feynman teorema