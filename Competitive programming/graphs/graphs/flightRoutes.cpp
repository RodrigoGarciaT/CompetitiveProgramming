#include <bits/stdc++.h>
using namespace std;
const long long N = 2*10e5;
long long n,m;
long long count1=0,count2=0;
bool visited1[N],visited2[N];
vector<long long>adj1[N],adj2[N];
void dfs1(long long node){
	if(visited1[node])return;
	visited1[node]=1;
	count1++;
	for(auto u:adj1[node]){
		dfs1(u);
	}
}

void dfs2(long long node){
	if(visited2[node])return;
	visited2[node]=1;
	count2++;
	for(auto u:adj2[node]){
		dfs2(u);
	}
}
int main() {
	cin>>n>>m;

	for(long long i =0;i<m;i++){
		long long a,b;
		cin>>a>>b;
		adj1[a].push_back(b);
		adj2[b].push_back(a);
	}

	dfs1(1);
	dfs2(1);

	if(n==count1&&count1==count2){
		cout<<"YES"<<endl;
		return 0;
		}else if(count1<n){
			cout<<"NO"<<endl;
			for(long long i =1;i<=n;i++){
				if(!visited1[i]){
					cout<<1<<' '<<i<<endl;
					return 0;
				}
			}
		}else{
			cout<<"NO"<<endl;
			for(long long i =1;i<=n;i++){
				if(!visited2[i]){
					cout<<i<<' '<<1<<endl;
					return 0;
				}
			}
		}
}
