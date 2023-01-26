#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e9 + 5);
const long long MAXL = long long(1e18 + 5);
const long long MOD = long long(1e9 + 7);
const long long MOD2 = long long(998244353);
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return;
}
void precision(int x) {
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(x);
  return;
}
long long gcd(long long a, long long b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0) {
    return b;
  }
  if (a == b) {
    return a;
  }
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool is_prime(long long a) {
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
bool is_square(long long a) {
  long long b = long long(sqrt(a));
  return (b * b == a);
}
bool is_cube(long long a) {
  long long b = long long(cbrt(a));
  return (b * b * b == a);
}
int digit_sum(long long a) {
  int sum = 0;
  while (a) {
    sum += int(a % 10);
    a /= 10;
  }
  return sum;
}
long long binpow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if ((b & 1) == 1) {
      ans *= a;
    }
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long binpow_by_mod(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if ((b & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    b >>= 1;
    a *= a;
    a %= mod;
  }
  return ans;
}
long long factorial(int a) {
  int i;
  long long ans = 1;
  for (i = 2; i <= a; i++) {
    ans *= long long(i);
  }
  return ans;
}
long long factorial_by_mod(int a, long long mod) {
  int i;
  long long ans = 1;
  for (i = 2; i <= a; i++) {
    ans *= long long(i);
    ans %= mod;
  }
  return ans;
}
const int N = 100005;
int a[N];
int n;
long long t[N * 4];
void bld(int tl, int tr, int pos) {
  if (tl == tr) {
    t[pos] = a[tl];
    return;
  }
  int m = (tl + tr) / 2;
  bld(tl, m, pos * 2);
  bld(m + 1, tr, pos * 2 + 1);
  t[pos] = t[pos * 2] + t[pos * 2 + 1];
  return;
}
long long qry(int tl, int tr, int l, int r, int pos) {
  if (l > r) {
    return 0LL;
  }
  if (tl == l && tr == r) {
    return t[pos];
  }
  int m = (tl + tr) / 2;
  return (qry(tl, m, l, min(m, r), pos * 2) +
          qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}
long long dp[N][355];
void solve() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bld(1, n, 1);
  for (i = 1; i <= n; i++) {
    for (j = 1; j < 350; j++) {
      dp[i][j] = 0;
    }
  }
  int k = sqrt(n);
  while (k * (k + 1) < 2 * n) {
    k++;
  }
  long long x;
  dp[n][1] = a[n];
  for (i = n; i >= 1; i--) {
    for (j = 1; j <= k; j++) {
      dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
      if (i > j + 1) {
        x = qry(1, n, i - j - 1, i - 1, 1);
        if (dp[i][j] > x) {
          dp[i - j - 1][j + 1] = max(dp[i - j - 1][j + 1], x);
        }
      }
    }
  }
  int ans = 0;
  for (i = 1; i <= k; i++) {
    if (dp[1][i] != 0) {
      ans = i;
    }
  }
  cout << ans << endl;
  return;
}
void precalc() { return; }
int main() {
  fastio();
  precalc();
  int tests = 1, tc;
  cin >> tests;
  for (tc = 1; tc <= tests; tc++) {
    solve();
  }
  return 0;
}
