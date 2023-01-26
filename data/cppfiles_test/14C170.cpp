#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long poww(long long a, long long b, long long mod) {
  long long res = 1;
  if (b < 0) b = (b % (mod - 1) + mod - 1) % (mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void Max(long long& x, long long y) { x = max(x, y); }
void Min(long long& x, long long y) { x = min(x, y); }
void OK(bool yes) { cout << (yes ? "Yes\n" : "No\n"); }
const long long N = 200500, M = 2010, LN = (1 << 24), K = 17, Mx = 4e6 + 50,
                inf = 3e18, Mod1 = 1e9 + 7, Mod2 = 999997457;
const long double pi = acos(-1), eps = 1e-12;
long long Fact[N];
void init() {
  Fact[0] = 1ll;
  for (int i = 1; i < N; i++) Fact[i] = (1ll * Fact[i - 1] * i) % Mod;
}
int Cnk(long long x, long long y) {
  if (y > x) return 0;
  return (((Fact[x] * poww(Fact[y], -1, Mod)) % Mod) *
          poww(Fact[x - y], -1, Mod)) %
         Mod;
}
void Add(long long& x, long long y, int j = 0) {
  long long mod = Mod;
  if (j == 1) mod = Mod1;
  if (j == 2) mod = Mod2;
  x %= mod;
  y %= mod;
  if (x < 0) x += mod;
  if (y < 0) y += mod;
  x = (x + y >= mod ? x + y - mod : x + y);
}
long long dp[2020], a[2020];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T = 1;
  int Case = 1;
  init();
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i - a[i] >= 0) dp[i] = 1;
    }
    long long Ans = inf;
    if (k == 1) {
      for (int i = 1; i <= n; i++)
        if (a[i] <= i) Min(Ans, i - a[i]);
      if (Ans == inf)
        cout << -1 << '\n';
      else
        cout << Ans << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (i - a[i] < 0) continue;
      for (int j = 1; j < i; j++) {
        if (j - a[j] < 0) continue;
        if (i - a[i] >= j - a[j] && a[i] > a[j]) {
          Max(dp[i], dp[j] + 1);
          if (dp[i] >= k) {
            Min(Ans, i - a[i]);
          }
        }
      }
    }
    if (Ans < inf)
      cout << Ans << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
