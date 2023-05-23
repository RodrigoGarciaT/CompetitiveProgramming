// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
const ll N = 5001;
ll n, m, c;
vector<ll>adj[N];
//c*t^2
ll money[N];
ll maxTripMoney = 0;
vector<pair<ll,ll>>trips;

void dfs(ll city, ll mooney, ll time, ll tripLength){
	mooney = mooney + money[city];

	if(city == 1){
        trips.push_back({mooney, time});
        maxTripMoney = max(maxTripMoney, mooney);
		cout<<trips.size()<<endl;
    } 
	
	if(city == 1 && time > 0) return;

	if(/*(mooney-(c*time*time))<=maxTripMoney &&*/time>1000) return;

	for(auto u: adj[city]){
		dfs(u, mooney, time+1, tripLength+1);
	}
}

int main() {
	//setIO("time");
	cin>>n>>m>>c;
	for(ll i =1; i<=n;i++){
		cin>>money[i];
	}

	while(m--){
		ll a, b;
		cin>>a>>b;
		adj[a].push_back(b);
	}

	dfs(1,0,0,0);
/*
	ll maxMooney = 0;


	// c*t^2 == 1000
	// 1000/c = t^2
	// t= sqrt(1000/c)

	vector<ll>dp(1001);

	for(ll time = 0;time<=1000;time++){
		dp[time]= 0;
		for(auto trip: trips){
			if(trip.second<=time){
				dp[time] = max(dp[time], trip.first+ dp[time-trip.second]);
			}
		}
		maxMooney = max(maxMooney,dp[time]-c*time*time);
	}


	cout<<maxMooney<<endl;*/
	cout<<"finished"<<endl;


}
