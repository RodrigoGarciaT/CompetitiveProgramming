#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LONG_MAX
int main() {
	ll n, m, q;
	cin>>n>>m>>q;
	ll adj[501][501], distance[501][501];

	for(ll i =0;i<=n;i++){
		for(ll  j=0;j<=n;j++){
			adj[i][j] = 0;
		}
	}

	while(m--){
		ll a,b,w;
		cin>>a>>b>>w;
        if(adj[a][b]!=0){
            adj[a][b] = min(w,adj[a][b]);
			adj[b][a] = min(w,adj[a][b]);
        }else{
			adj[a][b] = w;
			adj[b][a] = w;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++) {
	for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
		if(distance[i][k] == INF || distance[k][j] ==INF){continue;}
		distance[i][j] = min(distance[i][j],
		distance[i][k]+distance[k][j]);
	}
	}
	}

	while(q--){
		ll a,b;
		cin>>a>>b;
		if(distance[a][b] == INF ){
			cout<<-1<<endl;
			}else{
				cout<<distance[a][b]<<endl;
			}
	}
}
