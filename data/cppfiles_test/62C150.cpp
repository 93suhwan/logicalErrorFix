#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a % b ? gcd(b, a % b) : b; }
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
long long qpow(long long a, long long b) {
  long long t = 1;
  while (b != 0) {
    if (b & 1) t = (t * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return t;
}
template <typename T>
void re(T& a) {
  for (auto& t : a) cin >> t;
}
template <typename T>
void pr(T& a) {
  for (auto& t : a) cout << t << " ";
  cout << endl;
}
int n, m, q;
const int N = 1005;
int a[N][N];
int b[N][N];
int dfs(int x, int y, int d) {
  if (!a[x][y]) return 0;
  if (d == 0) {
    return 1 + dfs(x - 1, y, 2);
  } else if (d == 1) {
    return 1 + dfs(x + 1, y, 3);
  } else if (d == 2) {
    return 1 + dfs(x, y - 1, 0);
  } else {
    return 1 + dfs(x, y + 1, 1);
  }
}
void solve() {
  cin >> n >> m >> q;
  long long ans = 0;
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      a[x][y] = 1;
    }
  }
  long long nm = max(n, m);
  b[1][1] = 1;
  for (int i = 1; i <= nm; ++i) {
    b[i][i] = b[i][i - 1] + 2 * i * i - 1;
    for (int j = i + 1; j <= nm; ++j) {
      b[i][j] = b[j][i] = b[i][j - 1] + 2 * i * i;
    }
  }
  ans = b[n][m];
  while (q--) {
    int x, y;
    cin >> x >> y;
    int f = a[x][y];
    a[x][y] = 1;
    int U = dfs(x, y, 0);
    int D = dfs(x, y, 1);
    int L = dfs(x, y, 2);
    int R = dfs(x, y, 3);
    long long tmp = U * R + D * L - 1;
    ans += f ? -tmp : tmp;
    cout << ans << endl;
    a[x][y] = f ^ 1;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
