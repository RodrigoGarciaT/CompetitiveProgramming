// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+1;
const ll mod = 1e9+7;
vector<ll>lis;

int main() {
	ll n, m;
	cin>>n>>m;
	
	ll dp[n+1][m+2]={{0}};
	memset(dp,0,sizeof(dp));
	
	for(ll i = 0; i <n;i++){
		ll a;
		cin>>a;
		lis.push_back(a);
		if(a!=0)dp[i][a] = 1;
	}

	ll ans = 1;

	//cout<<dp[0][1]<<endl;


	for(ll idx = 0; idx<n;idx++){
		ll multip = 0;
		for(ll num = 1; num <=m;num++){
			if(lis[idx])continue;

			dp[idx][num] =0;

			if(idx > 0){
				dp[idx][num] += dp[idx-1][num];
				dp[idx][num]%=mod;

				dp[idx][num] += dp[idx-1][num-1];
				dp[idx][num]%=mod;

				dp[idx][num] += dp[idx-1][num+1];
				dp[idx][num]%=mod;
			}else{
				dp[idx][num] =1;
			}	

			if(lis[idx] == 0 && (idx+1<n&&(abs(num-lis[idx+1]))<=1)){
				multip+=dp[idx][num]; 
			}
			if(lis[idx] == 0 && idx+1>=n){
				multip+=dp[idx][num]; 
			}
			//cout<<idx<<' '<<num<<' '<<dp[idx][num]<<endl;
		}
		//cout<<endl;

		if(lis[idx] == 0 && (idx+1<n&&lis[idx+1]!=0)){
				ans*=multip; 
				ans%=mod;
			}
			if(lis[idx] == 0 && idx+1>=n){
				ans*=multip; 
				ans%=mod;
			}
	}


	for(ll i = 1; i <n;i++){
			if(lis[i]!= 0 &&lis[i-1]!=0 ){
				if(abs(lis[i]-lis[i-1])>1){
					cout<<0<<endl;
					return 0;
				}
			}
	}

	cout<<ans<<endl;
}
