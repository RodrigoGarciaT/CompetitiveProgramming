#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
void solve(){
	if(n == 0)return;
	vector<ll>a(n+2);
	a[0] = 0;
	a[n+1] = 0;
	stack<pair<ll,ll>>s;
	s.push({0,0});
	ll count = 0;
	for(ll i =1; i<=n+1;i++){
		if(i<=n)cin>>a[i];
		while(s.top().first>=a[i] && s.size()>1){
			ll height = s.top().first;
			ll pos = i-1;
			s.pop();
			ll distance = pos-s.top().second;
			ll area = height *distance;
			count = max(count, area);
		}
		s.push({a[i],i});
	}
	cout<<count<<endl;
}
int main() {
	while(cin>>n){
		solve();
	}
}
