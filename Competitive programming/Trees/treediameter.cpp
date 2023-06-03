#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+1;
vector<ll>adj[N];
unordered_map<ll,ll>subordinates;
ll maxim = 0;
ll dfs(ll node, ll e){
    ll max1 = 0;
    ll max2 = 0;
	for(auto u: adj[node]){
		if (u == e) continue;
		ll a = dfs(u,node);
        if(a <= max2){
            max1 = max(max1,a);
            }else{
            max1 = max2;
            max2 = a;
        }
	}
	
    maxim = max(maxim, max2+max1+1);
	return max2+1;
}
int main() {
	ll n;
	cin>>n;
	for(ll i =1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);

	cout<<maxim-1<<endl;
}