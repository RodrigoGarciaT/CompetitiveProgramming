// minimum segment tree
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+1;
const ll mod = 1e9+7;
vector<ll>lis;

struct segtree {

    int size; 
    vector<long long> minimums;
    vector<long long> minimumCounts;
    void init(int n){
        size = 1;
        while(size < n)size *= 2;
        minimums.assign(2 * size, INT_MAX);
        minimumCounts.assign(2 * size, 0);
    }


    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
               minimums[x] = a[lx];
               minimumCounts[x] = 1;
            }
            return;
        }
        
        int m = (rx + lx) / 2;
        build(a, 2 * x +1, lx, m);
        build(a, 2 * x +2, m, rx);
        minimums[x] = min(minimums[2 * x + 1], minimums[2 * x + 2]);

        minimumCounts[x] = 0;
        if(minimums[x] == minimums[2 * x + 1])minimumCounts[x] += minimumCounts[2 * x + 1];
        if(minimums[x] == minimums[2 * x + 2])minimumCounts[x] += minimumCounts[2 * x + 2];
    } 
    void build(vector<int> &a){
        build(a, 0, 0 ,size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            minimums[x] = v;
            minimumCounts[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i, v, 2 * x + 2, m,  rx);
        }
        // recalculate sum
        minimums[x] = min(minimums[2 * x + 1], minimums[2 * x + 2]);
        minimumCounts[x] = 0;
        if(minimums[x] == minimums[2 * x + 1])minimumCounts[x] += minimumCounts[2 * x + 1];
        if(minimums[x] == minimums[2 * x + 2])minimumCounts[x] += minimumCounts[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0,  size);
    }

    long long minimum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx)return INT_MAX;
        if(lx >= l &&  rx <= r)return minimums[x];
        int m = (lx + rx) / 2;
        long long s1 = minimum(l, r, 2 * x + 1, lx, m);
        long long s2 = minimum(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }

    long long minimum(int l, int r){
        return minimum(l, r, 0, 0, size);
    }

    // calculando minimumCount

    long long minimumCount(int l, int r, int x, int lx, int rx, int target){
        if(lx >= r || l >= rx)return 0;
        if(lx >= l &&  rx <= r){
            if(minimums[x] == target) return minimumCounts[x];
            return 0;
        }
        int m = (lx + rx) / 2;
        long long s1 = minimumCount(l, r, 2 * x + 1, lx, m, target);
        long long s2 = minimumCount(l, r, 2 * x + 2, m, rx, target);

        return s1 + s2;
    }

    long long minimumCount(int l, int r, int target){
        return minimumCount(l, r, 0, 0, size, target);
    }
};
    

int main() {
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vector<int>a(n);
    for(int i  = 0; i < n; i++){
        cin >> a[i];
    }

    st.build(a);
    while(m--){
        int  op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r;
            cin >> l >> r;
            int minim = st.minimum(l, r);
            int counter = st.minimumCount(l, r, minim);
            cout << minim << ' '<< counter << endl;
        }
    }
}
