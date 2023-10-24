#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;

	ll w[n+1];
	ll W = 0;
	for(ll i = 1; i <=n;i++){
		cin>>w[i];
		W += w[i];
	}
	vector<bool>possible(W+1,false);
	//bool possible[W+1];
	ll counter = 0;
	possible[0] = true;
	for (int k = 1; k <= n; k++) {
		for (int x = W; x >= 0; x--) {
			if (possible[x] && x+w[k] <= W) possible[x+w[k]] = true;
		}
	}


	for(ll i = 1; i <= W;i++)if(possible[i])counter++;
	cout<<counter<<endl;

	for(ll i = 1; i <= W;i++)if(possible[i])cout<<i<<' ';
}
