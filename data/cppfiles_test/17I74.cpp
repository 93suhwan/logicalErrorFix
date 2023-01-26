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
//        cout << endl;
        vector<int> cnt(n + 1);
        for (int i = 0; i < 5; i++) {
            int p = 1;
            for (auto x : os[i]) {
                cnt[x.second] += (n - p);
                p++;
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, cnt[i]);
        }
        vector<int> go;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == mx) {
                go.push_back(i);
            }
        }
        int ans = -1;
        for (auto x : go) {
            set<int> s;
            for (int i = 0; i < n; i++) if (i != x) {
                s.insert(i);
            }
            map<int, int> cntx;
            for (int i = 0; i < 5; i++) {
                int f = 0;
                for (auto j : os[i]) {
                    if (f) {
                        cntx[j.second]++;
                        if (cntx[j.second] == 3) s.erase(j.second);
                        if (s.empty()) break;
                    } else if (j.second == x) {
                        f = 1;
                    }
                }
                if (s.empty()) {
                    ans = x + 1;
                    break;
                }
            }
            if (ans != -1) break;
        }
        cout << ans << '\n';
    }
    return 0;
}
