#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 1e6+1, m =1e9+7;
ll factorial[MAXN+1];

ll inverse(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inverse(m % i) % m;
}

long long binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}

int main() {

	factorial[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
	}

	ll n;
	cin>>n;
	ll result = 0;
	for(ll i = 1; i<=n;i++){
		result += (ll)pow(-1,i-1) * binomial_coefficient(n,i)* factorial[n-i]%m;
	}
	result = (factorial[n] - result)%m;
	result = (result+m)%m;
	cout<<result<<endl;
}

/*
inclusion exclusion problema conocido que asi se reduce

n! - (n 1)(n-1)! + (n 2)(n-2)! ... (n n)(n-n)!

los coeficientes binomiales son la cantidad de subsets que hay de esa cantidad, esto se
puede porque todos tienen la misma probabilidad de la union de 2 sin importar quienes sean es
la misma
*/