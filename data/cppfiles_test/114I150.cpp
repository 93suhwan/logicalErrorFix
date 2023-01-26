#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define f first
#define s second
#define db long double
#define pb push_back
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define have(y, x) (y).find(x) != (y).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <iii> viii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int mod = 1e9+7;
const db eps = 1e-13;
const int oo = 1e9;

// basic operations
int mul( int a , int b ) {
    return (1ll*a*b)%mod;
}
int add( int a , int b ) {
    return (a+b)%mod;
}
int sub( int a, int b ) {
    return (a-b+mod)%mod;
}
void addSelf( int& a, int b ) {
    if (b >= 0)
        a += b;
    else {
        a += b;
        a += mod;
    }
    a %= mod;
}
int n;
struct Item {
    vector <int> idxs;
    int sm = 0;
    Item() {
        idxs.assign(n, 0);
    }
    bool operator < (const Item& X) const {
        if (sm == X.sm) {
            return idxs < X.idxs;
        }
        return sm > X.sm;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<setprecision(8)<<fixed;
    cin>>n;
    vector < vector <int> > v(n);
    for (int i = 0; i < n; i++) {
        int k;cin>>k;
        for (int j = 0; j < k; j++) {
            int x;cin>>x;
            v[i].pb(x);
        }
    }
    set <Item> S;
    Item tmp;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int idx = v[i].size()-1;
        sm += v[i][idx];
        tmp.idxs[i] = idx;
    }
    map <vector <int>, bool> mp;
    int m;cin>>m;
    while(m--) {
        vector <int> tmp_m;
        for (int i = 0; i < n; i++) {
            int x;cin>>x;
            tmp_m.pb(x-1);
        }
        mp[tmp_m] = true;
    }
    tmp.sm = sm;
    S.insert(tmp);
    while(sz(S)) {
        auto it = S.begin();
        tmp = *it;
        if (mp.find(tmp.idxs) != mp.end()) {
            S.erase(it);
            for (int i = 0; i < n; i++) {
                Item nw;
                if (!tmp.idxs[i]) continue;
                int sm = tmp.sm;
                sm -= v[i][tmp.idxs[i]];
                sm += v[i][tmp.idxs[i]-1];
                nw.idxs = tmp.idxs;
                nw.idxs[i]--;
                nw.sm = sm;
                if (sz(S) <= 1e5) {
                    S.insert(nw);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout<<tmp.idxs[i]+1<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
}
