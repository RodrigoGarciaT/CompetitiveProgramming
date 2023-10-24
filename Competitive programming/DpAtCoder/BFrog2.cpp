#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];

	int dp[n] = {0};
	dp[1] = abs(arr[1] - arr[0]);
	for(int i = 1; i <= min(k, n-1); i++){
		dp[i] = abs(arr[i] - arr[0]);
	}
	for(int i = k+1; i < n; i++ ){
		dp[i] = INT_MAX;
		for(int j = 1; j <=k; j++){
			if(i-j>=0)dp[i] = min(dp[i], dp[i - j]+abs(arr[i]- arr[i-j]));
		}
	}
	cout << dp[n-1] << endl;

}
/*
lo mismo pero tenemos que tomar en cuenta que ahora puede 
saltar k puestos
*/