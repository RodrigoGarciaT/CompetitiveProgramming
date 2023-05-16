// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
	const long long N = 200;
    long long n;
    vector<long long>adj[N];
    vector<pair<pair<long long, long long>, long long>>cows;
    vector<bool>visited(N);
    long long counter = 1;

    long long dfs(long long node, long long counter){
        if(visited[node])return 0;
        visited[node]=1;
        counter++;
        for(auto u: adj[node]){
            counter += dfs(node,0);
        }
        return counter;
    }
int main() {
    cin>>n;
    for(long long i =1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cows.push_back({{a,b},c});
    }

    for(long long i =1;i<=n;i++){
        for(long long j =1;j<=n;j++){
            if(i==j)continue;
            long long x1,y1,x2,y2;
            x1 = cows[i].first.first;
            y1 = cows[i].first.second;
            x2 = cows[j].first.first;
            y2 = cows[j].first.second;
            long long distance;
            distance = sqrt(pow(x1-x2,2)+pow(y2-y1,2));
            if(distance<=cows[i].second){
                adj[i].push_back(j);
            }
        }
    }
    long long maxCounter = 0;
    for(long long i =1;i<=n;i++){
        maxCounter = max(dfs(i,0), maxCounter);
        fill(visited.begin(),visited.end(),0);
    }
    cout<<maxCounter<<endl;
}