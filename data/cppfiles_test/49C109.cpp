#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 3e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;
const db EPS = 1e-9;
const db PI = acos((db)-1);
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}
int mul(int a, int b) {
  int ret = (1LL * a * b) % MOD;
  return ret;
}
int pw(int a, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1 == 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    n = n >> 1;
  }
  return ret;
}
int inv(int a) { return pw(a, MOD - 2); }
int divide(int a, int b) { return mul(a, inv(b)); }
void solve() {
  int n;
  cin >> n;
  vi ina(MAXN);
  for (int i = 1; i < MAXN; i++) {
    ina[i] = inv(i);
  }
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int m = n - 1;
  int dp[(1 << m)];
  int h[(1 << m)][m];
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      dp[mask] = 0;
    }
    vi b(n - 1);
    int at = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      b[at] = a[j];
      at++;
    }
    int ai = a[i];
    at = 0;
    int k = 1;
    for (int mask = 0; mask < (1 << m); mask++) {
      for (int j = 0; j < m; j++) {
        int val = mask & (1 << j);
        if (val || mask == 0) continue;
        h[mask][j] = 1;
        for (int k = 0; k < m; k++) {
          if (mask & (1 << k)) {
            h[mask][j] = mul(h[mask][j], mul(b[j], ina[b[j] + b[k]]));
          }
        }
      }
    }
    for (int mask = (1 << m) - 1; mask >= 0; mask--) {
      dp[mask] = 1;
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        int val = mask & (1 << j);
        if (val == 0) continue;
        cnt++;
        for (int k = 0; k < m; k++) {
          if (mask & (1 << k)) continue;
          int aux = mul(b[j], ina[b[j] + b[k]]);
          dp[mask] = mul(dp[mask], aux);
        }
        int aux = mul(b[j], ina[ai + b[j]]);
        dp[mask] = mul(dp[mask], aux);
      }
      for (int sub = mask; sub < (1 << m); sub = (sub + 1) | mask) {
        if (sub == mask) continue;
        int x = dp[sub];
        int com = 0;
        for (int j = 0; j < m; j++) {
          int v1 = mask & (1 << j);
          int v2 = sub & (1 << j);
          if (v2 && v1 == 0) {
            com |= (1 << j);
          }
        }
        for (int j = 0; j < m; j++) {
          int v1 = mask & (1 << j);
          int v2 = sub & (1 << j);
          if (v1) {
            x = mul(x, h[com][j]);
          }
        }
        dp[mask] = add(dp[mask], -x);
      }
    }
    ans = add(ans, dp[0]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
