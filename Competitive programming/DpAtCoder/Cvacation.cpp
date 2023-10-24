#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n],b[n],c[n];
	for(int i = 0; i < n;i++){
		cin >>a[i] >>b[i]>>c[i];
	}
   
   int aDp[n] = {0};
   int bDp[n] = {0};
   int cDp[n+1] = {0};
	aDp[0] = a[0];
	bDp[0] = b[0];
	cDp[0] = c[0];
	for(int i = 1; i<n;i++){
		aDp[i] = max(bDp[i-1], cDp[i-1]) + a[i];
		bDp[i] = max(aDp[i-1], cDp[i-1]) + b[i];
		cDp[i] = max(bDp[i-1], aDp[i-1]) + c[i];
	}

	cout << max(aDp[n-1], max(bDp[n-1], cDp[n-1]));
}
/*
Es un dp donde tienes un estado por la mejor solucion de a, b y c
y esas dependen de las anteriores.
*/