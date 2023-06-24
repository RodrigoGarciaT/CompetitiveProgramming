#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e6+1, m =1e9+7;
ll factorial[MAXN+1];

ll inverse(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inverse(m % i) % m;
}

long long C(ll n, ll k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}



int main() {
	int k,n;
	cin>>k>>n;

	factorial[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
	}

	cout<<C(n+k-1,n);
}
