// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const long long N = 2*10e5;
long long n;
long long m;
bool visited[N];
vector<long long>adj[N];
long long traversed =0;
void dfs(long long node){
	if(visited[node])return;

	visited[node]=1;
	traversed++;
	for(auto u: adj[node]){
		dfs(u);
	}
}
int main() {
	setIO("revegetate");
	cin>>n>>m;
	for(int i = 0; i<m;i++){
		char c;
		long long a,b;
		cin>>c>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	long long counter =0;

	for(long long i =1; i<=n;i++){
		if(!visited[i]){
			counter++;
			dfs(i);
		}
	}

	//long long ans = pow((long long)10,counter+(n-traversed));
	//cout<<ans<<endl;
	string s = "1" + string((counter+(n-traversed)), '0');
	cout<<s<<endl;
}
