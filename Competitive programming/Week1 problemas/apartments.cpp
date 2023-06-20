#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>people(n),apartments(m);
	for(ll i =0; i<n;i++){
		cin>>people[i];
	}
	for(ll i =0; i<m;i++){
		cin>>apartments[i];
	}
	sort(people.begin(),people.end());
	sort(apartments.begin(),apartments.end());
	ll j =0,count =0;
	for(ll i =0;i<n;i++){
		bool found = 0;
		while(j<m && apartments[j]<people[i]){
			if(abs(people[i]-apartments[j])<=k){
				j++;
				count++;
				found = 1;
				break;
			}
			j++;
		}
		if(!found &&abs(people[i]-apartments[j])<=k){
			j++;
			count++;
		}
	
	}
	cout<<count<<endl;
	}
