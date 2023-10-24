#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;	
	multiset<ll>s;
	ll counter = 0;

	while(n--){
		ll a;
		cin>>a;

		auto it = s.upper_bound(a);
		if(it == s.end()){
			s.insert(a);
			counter ++;
			continue;
		}
		
		s.erase(it);
		s.insert(a);
	}

	cout<<counter<<endl;
}
