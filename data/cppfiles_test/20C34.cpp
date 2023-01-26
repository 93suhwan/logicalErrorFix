#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const long long MAXV = LLONG_MAX;
template <typename T1, typename T2>
inline void chmin(T1& x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void swapmin(T1& x, T2& y) {
  if (x > y) swap(x, y);
}
template <typename T1, typename T2>
inline void chmax(T1& x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
inline void swapmax(T1& x, T2& y) {
  if (x < y) swap(x, y);
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  a %= MOD;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ans;
}
long long fac[MAXN], ifac[MAXN];
void init() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  ifac[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; i--) {
    ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
  }
}
long long C(int n, int k) {
  if (k > n) return 0;
  return (((fac[n] * ifac[n - k]) % MOD) * ifac[k]) % MOD;
}
long long n, m, k;
void solve() {
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int> > prefix(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] -= '0';
      prefix[i + 1][j + 1] =
          prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + a[i][j];
    }
  }
  auto get_sum = [&](int x1, int y1, int x2, int y2) {
    return prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] +
           prefix[x1][y1];
  };
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = i + 4; k < n; k++) {
        for (int l = j + 3; l < m; l++) {
          int inside_cost = get_sum(i + 1, j + 1, k - 1, l - 1);
          int upper_cost = l - j - 1 - get_sum(i, j + 1, i, l - 1);
          int lower_cost = l - j - 1 - get_sum(k, j + 1, k, l - 1);
          int left_cost = k - i - 1 - get_sum(i + 1, j, k - 1, j);
          int right_cost = k - i - 1 - get_sum(i + 1, l, k - 1, l);
          int cur =
              inside_cost + upper_cost + lower_cost + left_cost + right_cost;
          chmin(ans, cur);
          if (ans == 0) break;
          if (inside_cost > 16 || upper_cost + lower_cost > 16 ||
              left_cost > 16)
            break;
        }
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    solve();
  }
}
