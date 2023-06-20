#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>primes;
ll cont =0;
void sieve(ll n){
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if(is_prime[i]){
			cont++;
			if(cont%100==1)cout<<i<<endl;
		}

		if (is_prime[i] && (long long)i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}

}
int main() {
	sieve(1e8);
	ll i = 0;
	while(i<primes.size()){
		cout<<primes[i]<<endl;
		i+=100;
	}
}
