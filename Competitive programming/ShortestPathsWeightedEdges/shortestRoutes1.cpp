#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LONG_MAX
int main() {
	ll n, m;
	cin>>n>>m;
	vector<pair<ll,ll>>adj[n+1];
	vector<ll>distance(n+1, INF);
	vector<bool>visited(n+1,false);
	while(m--){
		ll a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
		//adj[b].push_back({a,w});
		}

		priority_queue<pair<ll,ll>>q;

		q.push({0,1});
		distance[1] = 0;
		visited[1] = 0;
		while(!q.empty()){
			ll s = q.top().second;
			//cout<<s<<' '<<distance[s]<<endl;
			q.pop();
			if(visited[s])continue;
			visited[s]=true;
			for(auto u:adj[s]){
				ll b = u.first;
				ll w = u.second;
				//cout<<b<<' '<<w<<' '<<distance[s]<<endl;
				if(distance[s]+w <distance[b]){
					distance[b] = distance[s]+w;
					q.push({-distance[b], b});
				}
			}
		}

		for(ll i =1;i<n;i++){cout<<distance[i]<<' ';}
		cout<<distance[n]<<endl;
}
