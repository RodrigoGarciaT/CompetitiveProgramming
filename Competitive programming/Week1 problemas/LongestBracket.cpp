#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll,ll>freq;
bool visited[(ll)1e6];
vector<ll>currentCount((ll)1e6,0);
int main() {
	string s;
	cin>>s;
	stack<char>st,st2;
	ll cont =0, maxCont = 0;
	for(ll i =0;i<s.size();i++){
		if(s[i] =='('){
			st.push('(');
			cont++;
		}else{
			if(st.size()==0)currentCount[i] = -1;
			if(st.size()==1){
				currentCount[i] = cont*2;
				cont =0;
			}
			if(st.size()>0)st.pop();
		}
	}
	cont = 0;
	ll end = s.size()-1;
	for(ll i =s.size()-1;i>=0;i--){
		if(s[i] ==')'){
			st2.push(')');
			cont++;
		}else{
			if(st2.size()==0){
				currentCount[end] = -1;
				end = i-1;
			}
			if(st2.size()==1){
				currentCount[end] = cont*2;
				cont =0;
				end = i-1;
			}
			if(st2.size()>0)st2.pop();
		}
	}

	cont = 0;
	for(ll i =0;i<s.size();i++){
		if(currentCount[i] == -1){
			cont = 0;
		}else{
			cont+=currentCount[i];
			freq[cont]++;
		}
		maxCont = max(cont, maxCont);
	}
	if(maxCont == 0){
		cout<<0<<' '<<1<<endl;
		return 0;
	}
	cout<<maxCont<<' '<<freq[maxCont]<<endl;
}