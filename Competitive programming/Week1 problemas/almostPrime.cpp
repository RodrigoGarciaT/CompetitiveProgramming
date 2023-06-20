#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>coprime;
void sieve(int n){
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)2*i <= n) {
			for (int j = 2*i; j <= n; j += i){
				is_prime[j] = false;
				coprime[j]++;
				}		
		}
	}
}
int main() {
	int n, cont = 0;
	cin>>n;
	sieve(3000);
	for(int i =1;i<=n;i++){
		if(coprime[i] == 2){
			cont++;
			//cout<<i<<endl;
		}
	}
	cout<<cont<<endl;
}
