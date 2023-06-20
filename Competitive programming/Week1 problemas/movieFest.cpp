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
	ll n;
	vector<pair<ll,ll>>movies;
	cin>>n;
	for(ll i =0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		movies.push_back({a,b});
	}
	sort(movies.begin(),movies.end(),cmp);

	pair<ll,ll>last = {0,0};
	ll cont = 0;
	for(auto i: movies){
		if(i.first>=last.second){
			last = i;
			cont++;
		}
	}
	cout<<cont<<endl;
}
