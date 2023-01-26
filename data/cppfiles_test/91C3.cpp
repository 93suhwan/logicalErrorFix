#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void debug(int x = 0) { cout << "--ok(" << x << ")" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
const int N = 1e5 + 5, M = 3e5 + 5, mod = 998244353;
int f[2][N], a[N];
vector<int> v[2];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int t = 0;
  int ans = 0;
  memset(f, 0, sizeof(f));
  v[0].clear();
  v[1].clear();
  for (int i = n; i >= 1; i--) {
    t = t ^ 1;
    memset(f[t], 0, sizeof(f[t]));
    v[t].clear();
    f[t][a[i]] = 1;
    v[t].push_back(a[i]);
    int last = a[i];
    for (auto& x : v[t ^ 1]) {
      int k = (a[i] + x - 1) / x;
      int y = a[i] / k;
      f[t][y] = (f[t][y] + f[t ^ 1][x]) % mod;
      if (last != y) v[t].push_back(y), last = y;
      ans = (ans + (long long)i * f[t ^ 1][x] * (k - 1) % mod) % mod;
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
