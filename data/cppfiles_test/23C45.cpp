#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 4000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
ll a[maxn + 5];
ll dp[maxn + 5][maxn + 5];
int solve(int l, int r, int m) {
  if (l > r) return 0;
  ll mn = a[l];
  int mid = l;
  for (auto i = l + 1; i <= r; i++)
    if (chmin(mn, a[i])) mid = i;
  int ls = solve(l, mid - 1, m);
  int rs = solve(mid + 1, r, m);
  int L = mid - l, R = r - mid;
  for (auto x = 0; x <= L; x++)
    for (auto y = 0; y <= R; y++) {
      ll tmp = dp[ls][x] + dp[rs][y] + 1ll * x * (m - x) * (a[ls] - a[mid]) +
               1ll * y * (m - y) * (a[rs] - a[mid]);
      chmax(dp[mid][x + y], tmp);
      chmax(dp[mid][x + y + 1], tmp);
    }
  return mid;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (auto i = 1; i <= n; i++) scanf("%lld", &a[i]);
  printf("%lld\n", dp[solve(1, n, m)][m]);
  return 0;
}
