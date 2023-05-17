#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll,ll>m;

vector<bool>sieve(32000);
vector<ll>primes;

void Sieve(){
	for(ll x =2; x<=32000;x++){
		if(sieve[x])continue;

		primes.push_back(x);
		for(ll u =2*x;u<=32000;u+=x){
			sieve[u] = x;
		}
	}
}
ll factors(ll n){
	if(m[n]!=0)return m[n];

	ll orig = n;
	ll count =0;
	for(ll x:primes){
		while(n%x==0){
			n/=x;
			count++;
			/*if(count>=30){
				m[orig] = count;
				return count;
			}*/
		}	
}
	if(n>1)count++;
	
	m[orig] = count;
	return count;
}


int main() {
	ll t;
	cin>>t;

	Sieve();
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
	

		if(c==1){
			if((max(a,b)%(min(a,b)))==0&&((max(a,b)/(min(a,b))))!=1){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
			continue;
		}else{  
			ll count = 0;
			if(m[a]+m[b]>=c){
				cout<<"YES"<<endl;
				continue;}
			if(a<b){
				factors(a);
				if(m[a]+m[b]>=c){
				cout<<"YES"<<endl;
				continue;
			}}
			else{
				factors(b);
				if(m[a]+m[b]>=c){
				cout<<"YES"<<endl;
				continue;	
			}}
			count = factors(a)+factors(b);
			if(count>=c){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
}
/*
 lo primero es darse cuenta que con los factores primos lo mejor es simplificar a 1
 lo segundo la observacion de que simplificamos con primos
*/