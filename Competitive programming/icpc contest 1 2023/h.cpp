#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+1;
ll mod =1e9+7;
ll n;
ll A = 31;
ll B = 1e9+9;
string obj;
vector<string>candidates;

///hashing function
pair<vector<long long>,vector<long long>>  compute_hash(string const& s) {
	vector<long long> hash_value(s.size()), p_value(s.size());
    hash_value[0] = (ll)s[0];
	p_value[0] = 1;
    for (ll i =1; i < (ll)s.size();i++) {
		char c = s[i];
        hash_value[i] = (hash_value[i-1]*A + (ll)c) % B;
		p_value[i] = (p_value[i-1]*A)%B;
    }
    return {hash_value, p_value};
}

//substring hashing function
 long long hashSubstr(pair<vector<ll>,vector<ll>> &h, ll l, ll r){
	 if(l==0) return h.first[r];

	 ll hashValue = (h.first[r]-h.first[l-1]*h.second[r-l+1])% B;
		if(hashValue < 0){
			hashValue = (hashValue+B)%B;
		}
		return hashValue;
 }
int main() {
cin>>n;

for(ll i = 0; i<n;i++){
	string a;
	cin>>a;
	candidates.push_back(a);
}
cin>>obj;

//////compute hashing


//hashing 1
vector<pair<vector<ll>,vector<ll>>>hashCandidates1;
for(string candidate: candidates){
	hashCandidates1.push_back(compute_hash(candidate));
}
pair<vector<ll>,vector<ll>>targetHash1 = compute_hash(obj);

// hashing 2
A = 53;
B = 1e9+9;
vector<pair<vector<ll>,vector<ll>>>hashCandidates2;
for(string candidate: candidates){
	hashCandidates2.push_back(compute_hash(candidate));
}
pair<vector<ll>,vector<ll>>targetHash2 = compute_hash(obj);


vector<ll>count(obj.size()+1);
count[0] = 1;


for(ll i =0; i<(ll)obj.size();i++){
	
	for(ll j =0; j<candidates.size();j++){
		ll hash1, hash2, hash3, hash4;
		if(i-(ll)candidates[j].size()>=-1){
			hash1 = hashSubstr(targetHash1, i+1-candidates[j].size(), i);
			hash2 = hashCandidates1[j].first.back();

			hash3 = hashSubstr(targetHash2, i+1-candidates[j].size(), i);
			hash4 = hashCandidates2[j].first.back();
		}
		if((i-(ll)candidates[j].size()>=-1&&hash1 == hash2)&&hash3 == hash4){
				count[i+1]= count[i+1] + count[i+1-candidates[j].size()];
				count[i+1] %= mod;
			}
	}
}
	cout<<max(count[obj.size()],(ll)0)<<endl;
}
