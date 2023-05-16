// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#define INF 1000000007
long long n,m;
const long long N=2*10e5;
bool visited[N];
long long x1= INF,y = INF;
long long y2=0,x2=0;
vector<pair<long long, long long>> pos;
vector<long long>adj[N];
void dfs(long long node){
	if(visited[node])return;
	visited[node] = 1;
	x1 = min(x1, pos[node].first);
	x2 = max(x2, pos[node].first);
	y = min(y, pos[node].second);
	y2 = max(y2, pos[node].second);
	for(auto u: adj[node])dfs(u);
}
int main() {
	setIO("fenceplan");
	cin>>n>>m;
	pos.push_back({0,0});
	for(int i =1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		pos.push_back({a,b});
	}

	for(int i =1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	long long minPer = INF;
	for(int i =1;i<=n;i++){
		if(!visited[i]){dfs(i);

		minPer = min(minPer,2*abs(x1-x2)+2*abs(y-y2));
		x1= INF,y = INF;
		y2=0,x2=0;}
	}
	cout<<minPer<<endl;
}
