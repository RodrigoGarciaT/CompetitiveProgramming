#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	ll dp[n+1];
	ll h[n+1];
	for(ll i =1; i<=n;i++){
		cin>>h[i];
		if(i==1){
			dp[i]= 0;
		}
		else if(i == 2){
			dp[i]= abs(h[i]-h[i-1]);
		}
		else{
		dp[i]= min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
		}
	}
	cout<<dp[n];
}
