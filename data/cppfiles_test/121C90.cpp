#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const long long mod = (long long)1e9 + 7;
const long long MOD = (long long)998244353;
const long long INF = (long long)1e18;
inline long long add(long long a, long long b) {
  return (a + b >= mod ? a + b - mod : a + b);
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long t[2][2] = {};
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    t[a[i] - '0'][b[i] - '0']++;
  long long ans = INF;
  if (t[0][1] == t[1][0]) ans = t[0][1] + t[1][0];
  if (t[1][0]) {
    long long n10 = t[0][0] + 1;
    long long n01 = t[1][1];
    if (n10 == n01) ans = min(ans, 1 + n01 + n10);
  }
  if (t[1][1]) {
    long long n10 = t[0][0];
    long long n01 = t[1][1] - 1;
    if (n01 == n10) ans = min(ans, 1 + n01 + n10);
  }
  if (ans == INF) ans = -1;
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  for (__typeof(t) i = (0) - ((0) > (t)); i != (t) - ((0) > (t));
       i += 1 - 2 * ((0) > (t)))
    solve();
  return 0;
}
