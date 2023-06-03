#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+1;
vector<ll>adj[N];
unordered_map<ll,ll>subordinates;


ll dfs(ll node){
	ll count =0;
	for(auto u: adj[node]){
		count += dfs(u);
	}
	subordinates[node] = count;
	return count+1;
}
int main() {
	ll n;
	cin>>n;
	for(ll i =2;i<=n;i++){
		ll a;
		cin>>a;
		adj[a].push_back(i);
	}
	dfs(1);

	for(ll i =1; i<n;i++){
		cout<<subordinates[i]<<' ';
	}
	cout<<subordinates[n]<<endl;
}
