#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin>>n;
	unordered_map<ll,ll>count;
	unordered_set<ll>s;
	ll currGcd = 0;
	for(int i =0;i<n;i++){
		ll a;
		cin>>a;
		currGcd = max(currGcd, a);
		s.insert(a);
		count[a]++;
	}
	vector<ll>ans;
	while(!s.empty()){
		ll bestNum =-1;
		ll onGoingGcd;
		for(auto i:s){
			if(bestNum == -1){
				bestNum = i;
			}else{
				if(__gcd(currGcd,i) > onGoingGcd){
					bestNum = i;
				}
			}
			onGoingGcd = __gcd(currGcd,bestNum);
		}
		currGcd = __gcd(currGcd,bestNum);
		s.erase(bestNum);
		for(ll j =0; j<count[bestNum];j++){
			ans.push_back(bestNum);
		}
	}

	for(ll i =0; i<n-1;i++){
		cout<<ans[i]<<' ';
	}
	cout<<ans[n-1]<<endl;
}
int main() {
ll t;
cin>>t;
while(t--){
	solve();
}
}
// basicamente hacemos gcd cada vez