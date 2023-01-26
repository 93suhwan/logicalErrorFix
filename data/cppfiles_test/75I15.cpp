#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template<typename _T, typename _cmp = less<_T>> 
using ordered_set = __gnu_pbds::tree<_T, __gnu_pbds::null_type, _cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

ll n;
vector<ll> a;

bool func(ll l, ll r, ll prev){
    if (a[l] <= prev && a[r] <= prev) return false;
    if (l == r) return true;
    if (!func(l, r - 1, a[r])) return true;
    return !func(l, r - 1, a[r]);
}

void solve(){
    cin >> n;
    a.resize(n);
    for (ll &x: a) cin >> x;
    cout << (func(0, n - 1, -1) ? "Alice" : "Bob");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        // cerr << "Case #" << i << ": \n";
        solve();
    }
    return 0;
}