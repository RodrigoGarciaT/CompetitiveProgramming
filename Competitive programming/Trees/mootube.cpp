#include <bits/stdc++.h>
using namespace std;
void setIO(string prob) {
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}

typedef long long ll;
const ll N = 5001;
vector<pair<ll,ll>>adj[N];
vector<ll>subordinates(N,0);
ll n, q;
ll dfs(ll node, ll k, ll e){
	ll count =0;
	for(auto u: adj[node]){
        if (u.first == e) continue;

		if(u.second>=k){
            count += dfs(u.first,k, node);
           // cout<<node<<' '<<u.first<<' '<<u.second<<' '<<k<<endl;
            }
	}
	subordinates[node] = count;
	return count+1;
}
int main() {
    setIO("mootube");
    cin>>n>>q;

    for(ll i =0; i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    while(q--){
        ll k, v;
        cin>>k>>v;
        cout<<dfs(v,k,0)-1<<endl;
    }
}
