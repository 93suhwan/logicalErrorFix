#include <bits/stdc++.h>
constexpr int maxn = 2e5 + 5;
constexpr int inf = 1e9;
constexpr int mod = 1e9 + 7;
using namespace std;
using lint = long long;
using pii = pair<int, int>;
int t, n;
string s, x;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    x = s;
    int ans = 0;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
      if (s[i] != x[i]) ans++;
    cout << ans << '\n';
  }
}
