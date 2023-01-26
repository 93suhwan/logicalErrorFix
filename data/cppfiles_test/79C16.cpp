#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned;
using i16 = short;
using u16 = unsigned short;
using ld = long double;
using ii = pair<int, int>;
const int N = 3e5 + 1;
int dp[N][2], p[N][2];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  priority_queue<tuple<int, int, int>> q;
  set<int> S;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) p[i][j] = -1;
    S.insert(i);
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  a[0] = b[0] = b[n] = dp[n][1] = 0;
  q.emplace(0, 1, n);
  p[n][1] = n;
  while (!q.empty()) {
    auto [c, y, x] = q.top();
    q.pop();
    if (y == 1) {
      auto k = S.lower_bound(x - a[x]);
      while (k != S.end() && *k < x) {
        int z = *k;
        dp[z][0] = 1 + dp[x][y];
        p[z][0] = x;
        q.emplace(-dp[z][0], 0, z);
        k = S.erase(k);
      }
    } else {
      if (p[x + b[x]][1] == -1) {
        dp[x + b[x]][1] = dp[x][y];
        p[x + b[x]][1] = x;
        q.emplace(-dp[x][y], 1, x + b[x]);
      }
    }
  }
  if (p[0][0] == -1) {
    cout << "-1\n";
    return;
  }
  vector<int> j;
  for (int x = 0, y = 0; x < n; x = p[x][y], y ^= 1)
    if (!y) j.push_back(x);
  reverse(j.begin(), j.end());
  cout << dp[0][0] << '\n';
  for (int x : j) cout << x << ' ';
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
