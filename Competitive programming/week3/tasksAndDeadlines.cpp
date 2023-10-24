#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	vector<pair<ll,ll>>task;
	ll award = 0;
	for(ll i =0;i<n;i++){
		ll a, b;
		cin>>a>>b;
		task.push_back({a,b});
		award +=b;
	}

	sort(task.begin(), task.end());

	ll acum = 0;
	for(auto i: task){
		acum += i.first;
		award -= acum;
	}
	cout<<award<<endl;
}
