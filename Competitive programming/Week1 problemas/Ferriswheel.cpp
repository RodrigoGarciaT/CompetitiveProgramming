#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n,x;
	cin>>n>>x;
	vector<ll>weight;
	for(ll i =0;i<n;i++){
		ll w;
		cin>>w;
		weight.push_back(w);
	}
	sort(weight.begin(),weight.end());
	ll p1 = 0, p2 = weight.size()-1,cont = 0;

	while(p1 < p2){
		if(weight[p1]+weight[p2]>x){
			p2--;
		}else{
			cont++;
			p1++;
			p2--;
		}
	}
	cout<<n-cont<<endl;
}