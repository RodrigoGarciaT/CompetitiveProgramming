#include <bits/stdc++.h>
using namespace std;
void setIO(string prob) {
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}
typedef long long ll;

//vector<ll>adj[maxN];
unordered_map<ll,vector<ll>>adjX, adjY;
int main() {
    setIO("lasers");
	//cout<<"hola"<<endl;
	ll n,x1,y1,x2,y2;
	cin>>n>>x1>>y1>>x2>>y2;
	ll N = n+1;
	vector<pair<ll, ll>> nodes;
	
	adjX[x1].push_back(0);
	adjY[y1].push_back(0);
	adjX[x2].push_back(1);
	adjY[y2].push_back(1);
	nodes.push_back({x1,y1});
	nodes.push_back({x2,y2});
	while(n--){
		ll xi, yi;
		cin>>xi>>yi;
		nodes.push_back({xi,yi});
		adjX[xi].push_back(nodes.size()-1);
		adjY[yi].push_back(nodes.size()-1);
	}
	//cout<<"hola"<<endl;

	ll x = 0;
	queue<ll> q;
	bool visited[1000000];
	ll distance[1000000];
	visited[x] = true;
	distance[x] = 0;
	distance[1] = -1;
	q.push(x);
	//cout<<"hola"<<endl;
	while (!q.empty()) {
		ll s = q.front(); q.pop();
		visited[s] = true;
		for (auto u : adjX[nodes[s].first]) {
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
		if(u == 1){
			cout<<distance[1]-1<<endl;
			return 0;
		}
		}

		for (auto u : adjY[nodes[s].second]) {
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
		if(u == 1){
			cout<<distance[1]-1<<endl;
			return 0;
		}
		}

	}
//cout<<"hola"<<endl;
	cout<<distance[1]<<endl;
	//cout<<"hola"<<endl;
}