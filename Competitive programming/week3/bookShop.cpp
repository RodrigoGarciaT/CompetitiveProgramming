// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
const ll m = 1e9+7;
const ll N = 1000, X = 1e5+1;
ll n,x;

int main() {
	sync;
	cin>>n>>x;	
	ll price[n];
	ll value[n];

	for(ll i = 0; i<n;i++)cin>>price[i];

	for(ll i = 0; i<n;i++)cin>>value[i];

	vector<ll>dp(x+1, 0);
	vector<bool>visited(x+1,false);
	visited[0] = true;
	ll ans = 0;
	for(ll bookIdx = 0; bookIdx<n;bookIdx++){
		for(ll money = x; money>=0;money--){

			if(visited[money] && money + price[bookIdx] <= x){
				dp[money+price[bookIdx]] = max(dp[money]+value[bookIdx],dp[money+price[bookIdx]]);
				visited[money+price[bookIdx]] = 1;
				ans = max(ans,dp[money]+value[bookIdx]);
			}
			ans = max(ans,dp[money]);
		}
	}
	cout<<ans<<endl;
}
/*
En los knapsack problems, lo que hacemos para evitar que se repita un mismo peso, es que recorremos money de
arriba a a bajo asi cada peso se usa solo una vez porque por ejemplo el primer peso solo se puede usar cuando money es 0,
luego nunca mas se puede usar, esto por el orden de las cosas, sin este orden tan especifico, un orden alrevez por ejemplo
si se permitirian repetir.

si hacemos el orden alrevez es como un problema con coins ilimitados.
*/