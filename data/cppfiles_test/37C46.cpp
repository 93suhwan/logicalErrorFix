#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const int inf = 1e9;
const ll INF = 1e18;
const int M = 1e9 + 7;
int n, m, cnt[MAXN];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cnt[i] = 0;
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    cnt[b]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        cout << i << ' ' << j << '\n';
      }
      break;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
