#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll m = 1e9+7;
int main() {
	ll n;
	cin>>n;
	char grid[n][n];

	for(ll i =0;i<n;i++){
		for(ll j = 0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	ll ways[n][n];
	ways[0][0] = 1;
	if(grid[0][0] =='*')ways[0][0] = 0;


	for(ll i =0;i<n;i++){
		for(ll j = 0;j<n;j++){
			if(i==0&&j==0){
				continue;
			}
			ways[i][j] = 0;
			if(i-1>=0)ways[i][j] += ways[i-1][j];

			if(j-1>=0)ways[i][j] += ways[i][j-1];
			ways[i][j] %= m;

			if(grid[i][j] =='*')ways[i][j] = 0;

			//cout<<ways[i][j]<<' ';
			//if(i == 3 && j ==2)cout<<ways[i][j]<<' ';

		}
		//cout<<endl;
	}

	cout<<ways[n-1][n-1];
}
