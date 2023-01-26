#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
//#include <bits/stdtr1c++.h>
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define pll pair<ll,ll>
#define V vector
#define F first
#define S second
#define INF LLONG_MAX
using namespace std;
using namespace __gnu_pbds;
ll lcm(ll a, ll b){    return (a / __gcd(a, b)) * b;}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll m, n;
    cin >> m >> n;
    V<V<ll>> v(n, V<ll>(m));
    V<V<pll>> vp(n, V<pll>(m)), pp(m, V<pll>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            cin >> v[j][i];
            vp[j][i] = {v[j][i],i};
        }
    for(int i = 0;i < m; i++)
        for(int j = 0; j < n; j++)
            pp[i][j] = {v[j][i],i};
    V<pll> p, q;
    for(int i = 0; i < m; i++)  sort(pp[i].begin(), pp[i].end(), greater<pll>());
    for(int i = 0; i < n; i++){
        sort(vp[i].begin(), vp[i].end(), greater<pll>());
        p.pb(vp[i][0]);
    }
    sort(p.begin(), p.end(), greater<pll>());
    /*for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++)
            cerr << vp[i][j].F << "_" << vp[i][j].S << "\t";
        cerr << endl;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cerr << pp[i][j].F << "_" << pp[i][j].S << "\t";
        cerr << endl;
    }*/
    set<ll> s;
    ll res = INF, idx = -1;
    V<ll> used(m);
    for(int i = 0; i < n; i++){
        s.insert(p[i].S);
        res = min(res, p[i].F);
        used[p[i].S] = 1;
    }
    /*for(int i = 0; i < m; i++)
        cerr << used[i] << " ";
    cerr << endl;
    cerr << res << endl;*/
    if(s.size() < n)
        cout << res << endl;
    else{
        ll res = 0;
        for(int i = 0; i < m; i++){
            //cerr << res << endl;
            if(used[i]) res = max(res, pp[i][1].F);
            else{
                if(pp[i][0].F == pp[i][1].F)    res = max(res, pp[i][1].F);
            }
        }
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

