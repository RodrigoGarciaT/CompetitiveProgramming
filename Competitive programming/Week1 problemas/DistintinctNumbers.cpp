#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	unordered_set<int>s;
	while(n--){
		int a;
		cin>>a;
		s.insert(a);
	}
	cout<<s.size()<<endl;
}
