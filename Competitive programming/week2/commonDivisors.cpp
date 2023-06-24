#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
#define f first
#define s second

//unordered_map<ll ,bool>lookFor;
const ll N = 1e6+1;
vector<ll>lookFor(N,0),divCount(N,0);
//unordered_map<ll,ll>divCount;
//map<pair<ll,ll>,bool>visited;
//bool visited2[][];
ll n = 0,maxGcd = 1;
void sieve(){
    for (ll i = 1; i * i <= n; i++) {
			bool found = 0;
            for (ll j = i*i; j <= n; j += i){
				if(lookFor[j]/*&&!visited[{min(i,j/i),max(i,j/i)}]*/){
					divCount[i]++;
					divCount[j/i]++;
					if(i == j/i)divCount[i]--;
					if(divCount[i]>=2)maxGcd = max(maxGcd,i);
					if(divCount[j/i]>=2){
						//found = 1;
                        maxGcd = max(maxGcd,j/i);
                        //return;
                        }

					//visited[{min(i,j/i),max(i,j/i)}] = 1;
					//visited2[min(i,j/i)][max(i,j/i)] = 1;
				}
				if(found)return;
			}
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll a;
		cin>>a;
		if(lookFor[a] == 1)maxGcd = max(maxGcd,a);
		lookFor[a] = 1;
		n = max(a,n);
		
	}
	sieve();
	cout<<maxGcd<<endl;
}
