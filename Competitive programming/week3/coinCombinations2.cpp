#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
const ll m = 1e9+7;
int main() {
	sync;
	ll n,x;
	cin>>n>>x;
	vector<ll>coins(n);
	for(ll i =0;i<n;i++){
		cin>>coins[i];
	}
	vector<ll>solution(x+1,0);
	solution[0] = 1;
	for(auto coin: coins){
		//solution[i] = 0;
		for(ll i = 1; i<=x;i++){
			if((i-coin)>=0)solution[i] += solution[i-coin];
			
			solution[i]%=m;
		}
		//cout<<i<<' '<<solution[i]<<endl;
	}
	cout<<solution[x]<<endl;
}
