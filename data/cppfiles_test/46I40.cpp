#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T, typename comparator=less<T>> using set_order = tree<T, null_type, comparator, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1000000007;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("../inp.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll su = 0;
    map<ll, int> m;
    m[0]++;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            su += a[i];
            m[su]++;
        } else {
            if (su < a[i]) {
                su = 0;
            } else {
                su -= a[i];
                m[su]++;
            }
        }
    }
    vector<ll> rep;
    rep.reserve(m.size());
    int c = 0;
    for (auto &p:m) {
        rep.push_back(p.first);
        p.second = c++;
    }
    vector<int> v(m.size());
    ll res = 0;
    su = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int l = m[su], r = m[su + a[i]];
            for (int j = l; j < r; j++) v[j]++;
            su += a[i];
        } else {
            if (su < a[i]) {
                int l = m[0], r = m[su];
                for (int j = l; j < r; j++) {
                    res += (rep[j + 1] - rep[j]) * v[j];
                }
                fill(v.begin(), v.end(), 0);
                su = 0;
            } else {
                int l = m[su - a[i]], r = m[su];
                for (int j = l; j < r; j++) {
                    res += (rep[j + 1] - rep[j]) * v[j];
                };
                su -= a[i];
            }
        }
    }
    cout << res;
}
