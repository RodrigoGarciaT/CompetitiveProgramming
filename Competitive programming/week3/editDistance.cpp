#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	string x, y;
	cin>>x>>y;
	ll n = x.size();
	ll m = y.size();

	ll distance[n+1][m+1];
	distance[0][0] = 0;
	distance[1][0] = 1;
	distance[0][1] = 1;
	for(ll i = 0; i<=n;i++){
		for(ll j = 0;j<=m;j++){

			distance[i][j] = 5001;
			if(j > 0) distance[i][j] = min(distance[i][j-1]+1,distance[i][j]);
			if(i > 0) distance[i][j] = min(distance[i-1][j]+1,distance[i][j]);
			if(i > 0 && j > 0) distance[i][j] = min(distance[i-1][j-1]+(!(x[i-1] == y[j-1])),distance[i][j]);

			distance[0][0] = 0;
			distance[1][0] = 1;
			distance[0][1] = 1;
			//cout<<distance[i][j]<<' ';
		}
		//cout<<endl;
	}

	cout<<distance[n][m]<<endl;
}
/**
 piensa en todos los estados posibles y como puedes pasar de uno a otro, tmb 
 */