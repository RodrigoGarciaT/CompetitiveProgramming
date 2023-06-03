#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int>adj[N];

int n, m;
int main() {
	cin>>n>>m;

	while(m--){
		int a , b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

queue<int>q;
bool visited[N];
int distance[N];
int x = 1;
visited[x] = true;
distance[x] = 0;
q.push(x);
distance[n] = 0;
while (!q.empty()) {
	int s = q.front(); q.pop();
	// process node s
	for (auto u : adj[s]) {
		if (visited[u]){
			cout<<distance[s]+2<<endl;
			return 0;
		}
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
	}
}

cout<<-1<<endl;
	return 0;
}


