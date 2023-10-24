#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<long long, long long>> weights;
	long long n, W;
	cin >> n >> W;
	long long a, b;
	while(cin>>a>>b){
		weights.push_back({a,b});
	}
	long long size = 1e5 + 1;
	long long dp[size] = {0};
	dp[0] = 1;
	long long maxSol = 0;
	for(auto weight: weights){
		for(long long k = W; k>=0; k-- ){
			if(k - weight.first >=0 && dp[k - weight.first]) dp[k] = max(dp[k], dp[k - weight.first] + weight.second);

			maxSol = max(maxSol, dp[k]);
			//if(maxSol == 4 )cout<< maxSol << ' '<<k<<' '<<weight.second<<endl;
		}
	}

	cout << maxSol - 1<< endl;
}
/*
Un knapsack basico
*/