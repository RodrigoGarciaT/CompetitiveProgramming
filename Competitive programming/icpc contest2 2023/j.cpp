#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e5+1;
ll n,m,q;
vector<ll>adj[maxN];
set<ll>adjSet[maxN];

bool visited[maxN], visited2[maxN];
vector<ll>ways(maxN,1),groups(maxN), parent(maxN);
struct DSU {
	vector<ll> e;
	DSU(ll N) { e = vector<ll>(N, -1); }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)]; }

	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		//cout<<"Created union between "<<x<<"and "<<y<<" the representative node is: "<<e[x]<<' '<<x<<endl;
		return true;
	}
};
DSU dsu(maxN);
unordered_map<ll,ll>lastVisited;


void combine(ll first, ll second, ll representative){
	//cout<<representative<<' '<<first<<' '<<second<<endl;
	bool flag1 =0, flag2 = 0;
	for(auto u:adj[first]){
		if(!(adjSet[representative].count(u) > 0) && flag1 && dsu.get(u)!=representative){
			adj[representative].push_back(u);
			adjSet[representative].insert(u);
		}
		if(u ==lastVisited[first]) flag1 = true;
	}
	for(auto u:adj[second]){
		if(!(adjSet[representative].count(u) > 0) && flag2 && dsu.get(u)!=representative){
			adj[representative].push_back(u);
			adjSet[representative].insert(u);
		}
		if(u ==lastVisited[second]) flag2 = true;
	}
}

void dfs(ll node, ll e){
	if(visited[node])return;

	visited[node] = true;
	parent[node] = e;
	//cout<<"visited Node: "<<node<<endl;
	for(auto u: adj[node]){
		u = dsu.get(u);
		if(u == e)continue;

		if(visited[u]){
			//cout<<"found loop at intersection: "<<node<<' '<<u<<endl;
			ll actualNode = u;
			lastVisited[node] = u;
			ways[actualNode] = 2;
			while(lastVisited[actualNode] !=u && dsu.get(u) != dsu.get(node)){
				ll first, second, third;
				first= dsu.get(actualNode);
				second = dsu.get(lastVisited[actualNode]);

				dsu.unite(actualNode, lastVisited[actualNode]);
				actualNode = lastVisited[actualNode];
				ways[actualNode] = 2;

				third = dsu.get(actualNode);
				combine(first, second, third);
				//cout<<"Created union between "<<first<<"and "<<second<<" the representative node is: "<<third<<endl;
			}
			ll representative = dsu.get(u);
			dfs(representative, parent[u]);
			break;
		}else{
			lastVisited[node] = u;
			dfs(u, node);
		}
	}
}


void secondDfs(ll node, ll e, ll group){
	if(ways[node] == 2 || visited2[node])return;

	groups[node]  = group;
	visited2[node] = true;
	for(auto u: adj[node]){
		if(u == e)continue;

		secondDfs(u,node,group);
	}
}
int main() {
	cin>>n>>m>>q;

	while(m--){
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		adjSet[a].insert(b);
		adjSet[b].insert(a);
	}
	for(ll i = 1; i<=n;i++){
		if(!visited[i])dfs(i,0);
	}

	for(ll i =1;i<=n;i++){
		if(!visited2[i] && ways[i] == 1){
			secondDfs(i,0,i);
		}
	}

	while(q--){
		ll a, b;
		cin>>a>>b;
		if(ways[a] == 2 || ways[b] == 2){
			cout<<"NO"<<endl;
		}else if(groups[a] == groups[b]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}}


	/*	for(ll i =1;i<=n;i++){
			cout<<i<<' '<<dsu.get(i)<<endl;
	}*/
}
/*
5 4 3
1 2
5 4
3 1
2 5
1 3
5 3
3 4


5 5 2
1 2
2 3
3 4
4 1
5 1
1 2
5 1

7 7 3
1 2
2 3
3 1
4 5
5 6
6 4
6 7
1 2
4 6
5 7
*/