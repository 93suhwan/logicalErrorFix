#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 1e6 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n;
long long a[N];
int s[N], p = 0;
long long dp[N];
long long pre[N];
long long query(int l, int r) { return pre[r] - (l ? pre[l - 1] : 0); }
void main0() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dp[0] = pre[0] = 1;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    while (p && (a[s[p]] >= a[i])) {
      sum -= a[s[p]] * query(s[p - 1], s[p] - 1);
      sum %= mod;
      p--;
    }
    s[++p] = i;
    sum += a[i] * query(s[p - 1], s[p] - 1);
    sum %= mod;
    dp[i] = (-sum + mod) % mod;
    pre[i] = (pre[i - 1] + dp[i]) % mod;
  }
  long long ans = dp[n] * (n & 1 ? -1 : 1);
  ans = (ans + mod) % mod;
  cout << ans << endl;
}
