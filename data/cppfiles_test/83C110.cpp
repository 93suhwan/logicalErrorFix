#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
const double PI = 3.14159265358979323846;
const double eps = 1e-10;
const long long N = 5010;
long long n, a[N], f[N], lcp[N][N];
char s[N];
long long dfs(long long i, long long j) {
  if (i == j) return lcp[i][j] = n - i + 1;
  if (i == n || j == n) return lcp[i][j] = s[i] == s[j];
  if (lcp[i][j] != -1) return lcp[i][j];
  if (s[i] == s[j])
    return lcp[i][j] = dfs(i + 1, j + 1) + 1;
  else
    return lcp[i][j] = 0;
}
void solve() {
  cin >> n >> s + 1;
  for (decay<decltype(n + 2)>::type i = (0), _i = (n + 2); i < _i; ++i) {
    for (decay<decltype(n + 2)>::type j = (0), _j = (n + 2); j < _j; ++j) {
      lcp[i][j] = -1;
    }
  }
  long long ans = n;
  for (decay<decltype(n + 1)>::type i = (1), _i = (n + 1); i < _i; ++i) {
    a[i] = n - i + 1;
  }
  f[1] = n;
  for (long long i = 2; i <= n; i++) {
    f[i] = a[i];
    for (long long j = 1; j < i; j++) {
      if (s[j] < s[i])
        chkmax(f[i], f[j] + a[i]);
      else if (s[i] == s[j]) {
        long long len = dfs(i, j);
        if (s[j + len] < s[i + len]) {
          chkmax(f[i], f[j] + a[i] - len);
        }
      }
    }
    chkmax(ans, f[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
