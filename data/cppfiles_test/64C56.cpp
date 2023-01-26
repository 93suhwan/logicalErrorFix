#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 3, M = 2e5 + 3;
int MOD;
string s, t;
int n, m, pw[N], hs[N], ht, Z[N + M];
bool check_prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int add(int x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int mul(int x, int y) { return (x * 1LL * y) % MOD; }
int get_hash(int l, int r) {
  return add(hs[r], -mul(hs[l - 1], pw[r - l + 1]));
}
void init() {
  while (true) {
    MOD = uniform_int_distribution<int>(1e8, 1e9)(rng);
    if (check_prime(MOD)) break;
  }
  cin >> s >> t;
  n = s.size(), m = t.size();
  s = " " + s, t = " " + t;
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], 10);
  for (int i = 1; i <= n; ++i) hs[i] = add(s[i] - '0', mul(hs[i - 1], 10));
  for (int i = 1; i <= m; ++i) ht = add(t[i] - '0', mul(ht, 10));
  t += s.substr(1, n);
  Z[1] = n + m;
  int l = 1, r = 1;
  for (int i = 2; i <= n + m; ++i) {
    if (i > r) {
      l = r = i;
      while (r <= n + m && t[r] == t[r - l + 1]) ++r;
      Z[i] = r - l;
      r--;
    } else {
      int k = i - l + 1;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        l = i;
        while (r <= n + m && t[r] == t[r - l + 1]) ++r;
        Z[i] = r - l;
        r--;
      }
    }
  }
}
void solve() {
  init();
  for (int i = 1; i + 2 * (m - 1) - 1 <= n; ++i) {
    int x = get_hash(i, i + m - 2);
    int x2 = get_hash(i + m - 1, i + 2 * m - 3);
    x = add(x, x2);
    if (x == ht) {
      cout << i << ' ' << i + m - 2 << '\n'
           << i + m - 1 << ' ' << i + 2 * m - 3;
      return;
    }
  }
  for (int i = 1; i + m - 1 <= n; ++i) {
    int x = get_hash(i, i + m - 1);
    if (m - Z[i + m] > 0) {
      if (i - m + Z[i + m] > 0) {
        int x2 = get_hash(i - m + Z[i + m], i - 1);
        x = add(x, x2);
        if (x == ht) {
          cout << i - m + Z[i + m] << ' ' << i - 1 << '\n'
               << i << ' ' << i + m - 1;
          return;
        }
        x = add(x, -x2);
      }
      if (i + 2 * m - Z[i + m] - 1 <= n) {
        int x2 = get_hash(i + m, i + 2 * m - Z[i + m] - 1);
        x = add(x, x2);
        if (x == ht) {
          cout << i << ' ' << i + m - 1 << '\n'
               << i + m << ' ' << i + 2 * m - Z[i + m] - 1;
          return;
        }
        x = add(x, -x2);
      }
    }
    if (m - Z[i + m] - 1 > 0) {
      if (i - m + Z[i + m] + 1 > 0) {
        int x2 = get_hash(i - m + Z[i + m] + 1, i - 1);
        x = add(x, x2);
        if (x == ht) {
          cout << i - m + Z[i + m] + 1 << ' ' << i - 1 << '\n'
               << i << ' ' << i + m - 1;
          return;
        }
        x = add(x, -x2);
      }
      if (i + 2 * m - Z[i + m] - 2 <= n) {
        int x2 = get_hash(i + m, i + 2 * m - Z[i + m] - 2);
        x = add(x, x2);
        if (x == ht) {
          cout << i << ' ' << i + m - 1 << '\n'
               << i + m << ' ' << i + 2 * m - Z[i + m] - 2;
          return;
        }
        x = add(x, -x2);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
