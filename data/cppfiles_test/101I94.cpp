#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxN = 2e5 + 1;
pair<ll, char> a[maxN];
char colors[maxN];
void solve() {
    // code here
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first;
    cin >> colors;

    for (int i = 0; i < n; i++) a[i].second = colors[i];

    sort(a, a + n, [](auto &p, auto &q) -> bool {
        if (p.second == q.second) return p.first < q.first;
        return p.second == 'B';
    });

    string ans = "YES\n";
    for (int i = 0; i < n; i++) {
        auto [num, color] = a[i];
        cout << "(" << num << "," << color << ") ";
        if (color == 'B' && num < i + 1) {
            ans = "NO\n";
            break;
        }
        if (color == 'R' && num > i + 1) {
            ans = "NO\n";
            break;
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T;
    cin >> T;
    while (T--) solve();
    return 0;
}