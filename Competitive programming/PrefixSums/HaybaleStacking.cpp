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

ll n,k;
ll maxK = 25000;

int main(){
    sync;
    //setIO("name");
    cin>>n>>k;
    vi cowAmounts(k+1,0);
    vi startPoint;
    vi endPoints;
    FOR(i, 0,k){
        ll s,e;
        cin>>s>>e;
        startPoint.pb(s);
        endPoints.pb(e);
    }
    sort(all(startPoint));
    sort(all(endPoints));

    ll cowsAdded=0;
    ll sit =0;
    ll eit = 0;

    FOR(i,1,n+1){
        while(i>=startPoint[sit]&&sit<startPoint.size()){
            cowsAdded++;
            sit++;
        }
        while(i>endPoints[eit] && eit<endPoints.size()){
            cowsAdded--;
            eit++;
        }
        cowAmounts[cowsAdded]++;
    }
    ll middle = n/2+1;
    ll acum = 0;
    FOR(i,0,k+1){
        acum+=cowAmounts[i];
        if(acum>=middle){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}