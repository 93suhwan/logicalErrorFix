#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sz(x) int32_t(x.size())
#define pii pair < int, int >
#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define _ << ' ' <<
#define se second
#define fi first
// #define int ll

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 5;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int ans = 10;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                cnt1 += (s[i] != '0');
            }
            else {
                cnt2 += (s[i] == '1');
            }

            int r = 9 - i;
            if (i % 2 == 0 && cnt1 - cnt2 > (r + 1) / 2) {
                ans = min(ans, i + 1);
            }
        }

        cnt1 = cnt2 = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                cnt2 += (s[i] == '1');
            }
            else {
                cnt1 += (s[i] != '0');
            }

            int r = 9 - i;
            if (i % 2 && cnt1 - cnt2 > r / 2) {
                ans = min(ans, i + 1);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
