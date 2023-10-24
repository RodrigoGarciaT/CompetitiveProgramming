// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
void setIO(string prob) {
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}
int main() {
	sync;
    setIO("breedflip");
	ll counter = 0;
	bool found = 0;	
	ll n;
	cin>>n;
	string a, b;
	cin>>a>>b;

	for(ll i =0; i<n;i++){
		if(a[i]!=b[i]){
			if(!found){
				counter++;
			}
			found = 1;
		}else{
			found = 0;
		}
	}
	cout<<counter<<endl;
}
