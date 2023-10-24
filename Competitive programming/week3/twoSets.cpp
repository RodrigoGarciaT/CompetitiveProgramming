#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = 1e9+7;
ll inverse(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inverse(m % i) % m;
}
int main() {
	ll n;
	cin>>n;
	if((n*(n+1)/2)%2){
		cout<<0<<endl;
		return 0;
	}

	ll target = n*(n+1)/4;


	vector<ll>cont(target+2,0);
	vector<bool>possible(target+2, false);
	possible[0] = 1;
	cont[0] = 1;
	for(ll k = 1; k<=n;k++){
		for(ll x = target; x>=0;x--){
			if(possible[x]&&x+k<=target){
				cont[x+k] += cont[x];
				cont[x+k]%=m;
				possible[x+k] = 1;
				//cout<<x<<endl;
			}
		}
	}
	cout<<cont[target]*inverse(2)%m<<endl;
}
