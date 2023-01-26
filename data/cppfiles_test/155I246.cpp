#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &u: a) {
            cin >> u;
        }
        vector<int> b[2];
        for (int i = 0 ; i < n ; i++) {
            char h;
            cin >> h;
            if (h == '1') {
                b[1].push_back(a[i]);
            }
            else {
                b[0].push_back(a[i]);
            }
        }
        for (int u: b[0]) {
            cout << u << " ";
        }
        for (int u: b[1] ){
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}
