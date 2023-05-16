#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ll, ll>> viii;
 
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18
#define MAX 200050
void setIO(string prob) {
	freopen((prob + ".in").c_str(), "r", stdin);
	freopen((prob + ".out").c_str(), "w", stdout);
}


void solve(){
    ll n;
    ll suma = 0;
    cin>>n;
    ll psums [n+1];
    psums[0]=0;
    string numbers;
    cin>>numbers;
    unordered_map<ll, ll> allowed;
    allowed[0]=1;
    FOR(i,1,n+1){
        psums[i]=ll(numbers[i-1])-48;
        psums[i]+=psums[i-1];
       // cout<<"psums "<<i<<": "<<psums[i]<<endl;
        suma+=(allowed[psums[i]-i]);
        allowed[psums[i]-i]++;
         }

    cout<<suma<<endl;
}

int main(){
    sync;
    //setIO("name");
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}