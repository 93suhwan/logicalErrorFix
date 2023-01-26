#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) returns an iterator to the the kth element in the set (0-based indexing)
// order_of_key(k) returns the number of elements strictly less than k

#define int int64_t







void gogo() {
    ordered_set<int> o;
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    o.insert(a[0]);

    int ans = 0;
    for(int i = 1; i < n; i++) {
        int less = o.order_of_key(a[i]);
        int more = i - o.order_of_key(a[i] + 1);
        ans += min(less, more);
        o.insert(a[i]);
    }

    cout << ans << "\n";
    
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    while(tc--) gogo();

    return 0;
}