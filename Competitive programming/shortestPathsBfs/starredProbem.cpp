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
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
	}
}

if(distance[n] == 0){
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

// second bfs
//queue<int>q;
vector<int> ans;
x = n;
q.push(x);
while (!q.empty()) {
int s = q.front(); q.pop();
// process node s
for (auto u : adj[s]) {
if(distance[u] ==(distance[s]-1)){
	q.push(u);
	ans.push_back(u);
	break;
}

}
}


cout<<distance[n]+1<<endl;

for(int i = ans.size()-1; i>=0;i-- ){
	cout<<ans[i]<<' ';
}
cout<<n<<endl;
}
