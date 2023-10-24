// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<ll,ll>a,pair<ll,ll>b){
	if(a.second !=b.second){
		return a.second < b.second;
	}
	return a.first <b.first;
}
int main() {
	ll n, k;
	cin>>n>>k;
	vector<pair<ll,ll>>movies;
	multiset<ll>endTimes;
	for(ll i =0;i<n;i++){
		ll a, b;
		cin>>a>>b;
		movies.push_back({a,b});
	}

	//pair<ll,ll>prevMovie = {0,0};
	sort(movies.begin(),movies.end(),cmp);
	ll cont = 0;
	for(auto movie: movies){
		/*if(endTimes.size() < k){
			endTimes.insert(movie.second);
			cont++;
			//cout<<"movie 1: "<<movie.first<<' '<<movie.second<<endl;
			continue;
		}*/
		auto it = endTimes.lower_bound(movie.first);
		if(it != endTimes.end() && *it == movie.first){
			endTimes.erase(it);
			endTimes.insert(movie.second);
			cont++;
			//cout<<"movie 2:"<<movie.first<<' '<<movie.second<<endl;
			continue;
		}
		if(endTimes.size() > 0)it--;
		if(it != endTimes.end()&& *it <= movie.first){
			endTimes.erase(it);
		//	cout<<"movie 3:"<<movie.first<<' '<<movie.second<<" lastEnd: "<<*it<<endl;
			endTimes.insert(movie.second);
			cont++;
			continue;
		}
		if(endTimes.size() < k){
			endTimes.insert(movie.second);
			cont++;
			//cout<<"movie 1: "<<movie.first<<' '<<movie.second<<endl;
			continue;
		}
	}

	cout<<cont<<endl;
}
