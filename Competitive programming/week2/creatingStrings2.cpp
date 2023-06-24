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
	factorial[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
	}
	string s;
	cin>>s;
	unordered_map<char, ll>letter;

	for(auto i:s){
		letter[i]++;
	}

	ll total = 1, left = s.size();
	for(char i = 'a'; i<='z';i++){
		total = total*C(left, letter[i])%m;
		left -= letter[i];
	}
	
	cout<<total<<endl;
}
/*
en el ejemplo de ahi elijes 3 que sean a, del resto una b y del resto una c
(5 3)*(2 1)*(1 1)
*/