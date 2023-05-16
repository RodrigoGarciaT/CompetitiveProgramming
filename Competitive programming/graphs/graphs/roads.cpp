// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
	const int N = 200000;
	int n, m;
	vector<int> adj[N];
	bool visited[N];

void dfs(int node){
	if(visited[node])return;

	visited[node]=1;

	for(auto u: adj[node]){
		
		dfs(u);
	}
}
int main() {
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int count =0;

	vector<pair<int,int> > roads;

	int last = 0;

	for(int i =1;i<=n;i++){
		if(visited[i]){
			continue;
		}else{
			if(last!=0){
				roads.push_back({last, i});
			}
			last = i;
			count++;
			dfs(i);
		}
	}
	cout<<count-1<<endl;

	for(auto road: roads){
		cout<<road.first<<' '<<road.second<<endl;
	}
}

/*
contamos el numero de islas y se tienen que haces islas-l roads
guardamos los primeros elementos de cada isla y los conectamos
*/