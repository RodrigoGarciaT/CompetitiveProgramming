#include <bits/stdc++.h>
using namespace std;
#define ll int
set<int>s;
multiset<int>current;
int x,n;
int sumBetween(int target){
	if(target == x || target == 0){
		current.insert(target);
		return target;
	}

	s.insert(target);
	auto it = s.find(target);
	auto r = it, l = it;
	++r;
	--l;
	current.insert(*r-*it);
    current.insert(*it-*l);
	return *r-*l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>x>>n;
	s.insert(0);
	s.insert(x);
	current.insert(x);
	for(ll i =0;i<n;i++){
		ll a;
		cin>>a;
		current.erase(current.find(sumBetween(a)));
		if(i == (n-1)){
			cout<<*(--current.end())<<endl;
			break;
		}
		cout<<*(--current.end())<<' ';
	}
}
