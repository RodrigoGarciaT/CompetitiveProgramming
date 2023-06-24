#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = 1e9+7;

ll inv(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}

ll sumatory(ll n){
	n = n%m;
	ll sumat = n*(n+1)%m;
	sumat = sumat*inv(2)%m;
	return sumat;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll tot = 0;
	ll sqrn = (ll)sqrt(n);
	for(ll i = 1;i<=sqrn;i++){
		ll divs = (n/i)*i;
		ll sumOfMults;
		if((n/i)>=sqrn){
			sumOfMults = (sumatory(n/i) - sumatory(sqrn))%m;
			//sumOfMults = (sumOfMults+m)%m;
			while(sumOfMults<0){
				sumOfMults +=m;
			}
		}
		divs = (divs + sumOfMults)%m;
		tot = (tot+divs)%m;
	}

	cout<<tot<<endl;
}


