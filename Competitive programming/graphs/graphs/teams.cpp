// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
bool visited[N];
unordered_map<int,int>teams;
bool impossible = 0;
int n,m;


void dfs(int node,int team){
	if(visited[node])return;
	teams[node] = team;
	visited[node] = true;
	//cout<<node<<' '<<team<<endl;
	for(auto u: adj[node]){

		if(teams[node]==teams[u]){
			//cout<<node<<' '<<u<< ' '<<teams[node]<<' '<<teams[u]<<endl;
			impossible = 1;
		}
		if(visited[u])continue;
		int newTeam;
		if(team==2){
			newTeam =1;
		}else{
			newTeam =2;
		}
		//cout<<team<<' '<<newTeam<<endl;
		dfs(u,newTeam);
	}
}
int main() {
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int team = 1;
	for(int i=1;i<=n;i++){
		if(visited[i])continue;

		dfs(i,team);
	}
	if(impossible){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<< teams[i]<<' ';
	}
	cout<<endl;
}
