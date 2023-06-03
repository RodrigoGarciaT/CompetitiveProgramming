#include <bits/stdc++.h>
using namespace std;
void setIO(string prob) {
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}
typedef long long ll;
const ll N = 1e5+1;
vector<ll>adj[N];
ll n, q;
vector<char>cow(N);
vector<ll>group(N);
bool visited[N];
void dfs(ll node, char cw, ll gr, ll parent){
    group[node] = gr;
    visited[node] = true;
    for(auto u: adj[node]){
        if(u == parent) continue;

        if(cow[u] == cw)dfs(u,cw,gr,node);
    }
}

int main() {
    setIO("milkvisits");
    cin>>n>>q;
    for(ll i = 1; i<=n;i++){
        cin>>cow[i];
    }

    for(ll i = 1; i<n;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i = 1; i<=n;i++){
        if(!visited[i]){
            dfs(i,cow[i],i,-1);
        }
    }

    while(q--){
        ll a, b;
        char c;
        cin>>a>>b>>c;
        if(cow[a] == c || cow[b] == c ){
            cout<<1;
        }else if(group[a] == group[b]){
            cout<<0;
        }else{
            cout<<1;
        }
    }
}
/*
noticing small things such as the fact that the only way you are not happy is if all the cows are from one color
]therefore you can dfs only the ones with the same color
*/