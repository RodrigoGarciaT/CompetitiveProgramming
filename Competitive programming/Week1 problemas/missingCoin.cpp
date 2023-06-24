#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	vector<ll>a(n);
	for(ll i =0; i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());

	ll lastPossible = 0;
	for(ll i =0;i<n;i++){
		if(a[i]-lastPossible > 1)break;
		lastPossible = lastPossible + a[i];
	}
	cout<<lastPossible+1<<endl;
}
