#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
	const long long N = 1500;
    long long n;
    vector<pair<long long, long long>>cows;
    vector<bool>visited(N);

    long long counter =0;

    void dfs(long long node, long long limit){
        if(visited[node])return;

        visited[node]=1;
        counter++;

        for(long long u =1;u<=n;u++){
            if(u==node)continue;
            long long x1,y1,x2,y2;
            x1 = cows[u].first;
            y1 = cows[u].second;
            x2 = cows[node].first;
            y2 = cows[node].second;
            long long distance;
            distance = pow(x1-x2,2)+pow(y2-y1,2);
            if(distance<=limit){
                dfs(u,limit);
            }
        }
    }

int main() {
    setIO("moocast");
    cin>>n;
    cows.push_back({0,0});
    for(long long i =1;i<=n;i++){
        long long a,b;
        cin>>a>>b;
        cows.push_back({a,b});
    }
    long long l =0, r=0;
    for(long long i =1;i<=n;i++){
        for(long long j =1;j<=n;j++){
            if(i==j)continue;
            long long x1,y1,x2,y2;
            x1 = cows[i].first;
            y1 = cows[i].second;
            x2 = cows[j].first;
            y2 = cows[j].second;
            long long distance;
            distance = pow(x1-x2,2)+pow(y2-y1,2);
            r = max(r,distance);
        }
    }
    r++;
    while(r>l+1){
        long long m = (r+l)/2;
        dfs(1,m);
        if(counter>=n){
            r=m;
        }else{
            l=m;
        }
        counter=0;
        fill(visited.begin(),visited.end(),0);
    }
    cout<<r<<endl;
}