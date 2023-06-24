#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n,x;
	cin>>n>>x;
	ll arr[n+1];
	arr[n] = x+1;
	for(ll i =0;i<n;i++){
		cin>>arr[i];
	}
	ll count = 0;
	ll current = 0;
	ll r = 0;
	for(ll l = 0; l<=n;l++){
		//cout<<current<<endl;
		//cout<<l<<endl;
		//if(l == 2)cout<<r<<' '<<current<<endl;
		r = max(r,l);
		while(current < x &&r<=n){
			if(current + arr[r] > x)break;
			current += arr[r];
			/*if(l ==4){
				cout<<r<<' '<<l<<' '<<current;
			}*/
			if(current == x){
				//cout<<r<<' '<<l<<' '<<current<<endl;
				count++;
				}
			r++;
		}
		current = max((ll)0,current-arr[l]);
	}

	cout<<count<<endl;
}
