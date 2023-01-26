#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
inline void solve() {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int l = -1, cnt = 0;
  for (int i = 0; i < t.size(); ++i) {
    bool ok = 0;
    for (int j = l + 1; j < s.size(); ++j)
      if (s[j] == t[i] && (j - l - 1) % 2 == 0) {
        ok = 1;
        l = j;
        break;
      }
    if (ok) cnt++;
  }
  if (cnt == t.size())
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
