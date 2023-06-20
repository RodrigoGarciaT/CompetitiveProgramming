#include <iostream>
using namespace std;
long long gcd (long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
long long lcm (long long a, long long b) {
    return (a*b) / gcd(a, b);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long a,b;
	    cin>>a>>b;
	    cout<<gcd(a,b)<<' '<<lcm(a,b)<<endl;
	}
	return 0;
}
