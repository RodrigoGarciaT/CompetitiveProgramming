#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll x, n;
	cin>>x>>n;
	multiset<ll>sticks;
	ll ans = 0;
	while(n--){
		ll a;
		cin>>a;
		sticks.insert(a);
	}

	while(sticks.size() >1){
		//cout<<"sticks size: "<<sticks.size()<<endl;
		auto it1 = sticks.begin();
		auto it2 = sticks.begin();
		it2++;
		ll newNum = *it1 + *it2;
		ans += newNum;
		sticks.erase(it1);
		sticks.erase(it2);
		sticks.insert(newNum);
		//cout<<newNum<<' '<<sticks.size()<<endl;
	}
	cout<<ans<<endl;
}
