// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
void solve(){
	ll arr[n+1];
	for(ll i =1;i<=n;i++)cin>>arr[i];

	ll minValue = n*(n-1)-(k*2*n);
	ll l = 2, r = n,ans=2;
	while(l<=r){
		ll m = (l+r)/2;
		if(m*(m-1)>=minValue){
			ans = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}

	ans--;
	ll maxValue = -999999;
	for(ll i =ans;i<n;i++){
		for(ll j = i+1;j<=n;j++){
			maxValue = max(maxValue,i*j-(k*(arr[i]|arr[j])));
		}
	}
	cout<<maxValue<<endl;
}
int main() {
	ll t;
	cin>>t;

	/*couit(k*(arr[i]|arr[j])*/
	
	while(t--){
		cin>>n;
		cin>>k;
		solve();
	}
}
/*
notice that k is very small

if you have a formula that involves operations within variables that have limits
try to figure out the limits, to see if they allow to shorten how many values 
do you look at

specially when looking for every possible value goes out of limit

*/