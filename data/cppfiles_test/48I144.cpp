#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define int long long
#define ll pair<long long, long long>

using namespace __gnu_pbds;
using namespace std;
tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> tr;

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        int inv = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            tr.insert(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            inv += tr.order_of_key(a[i]);
            tr.erase(a[i]);
        }
        if (inv % 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
