#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ordered_set<pair<int, int>> os[5];
        vector<vector<int>> a(n, vector<int>(5, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
                os[j].insert({a[i][j], i});
            }
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        int ans = -1;
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                pair<int, int> x = *os[j].begin();
                os[j].erase(x);
                cnt[x.second]++;
                if (cnt[x.second] == 5 && i < n - 1) {
                    ans = x.second + 1;
                    break;
                }
            }
            if (ans != -1) break;
        }
        cout << ans << '\n';
    }
    return 0;
}
