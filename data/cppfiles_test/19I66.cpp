#include <bits/stdc++.h>
using namespace std;
constexpr int mod = (int)998244353;
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long binmul(long long a, long long b) {
  long long res = 0;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}
long long area(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return abs(a.first * b.second + b.first * c.second + c.first * a.second -
             a.second * b.first - b.second * c.first - c.second * a.first);
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
double intlog(long long n, long long base) {
  return (double)log(n) / log(base);
}
long long t, m, temp, temp2, root, q, k, i, j, r, u, v, w, n, l, p;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
long long mid;
int solve(int i, int x, vector<long long> &a, vector<vector<int> > &dp) {
  if (x < 0 || x > mid) {
    return 0;
  }
  if (i == (int)a.size()) {
    return 1;
  }
  int &res = dp[i][x];
  if (res != -1) return res;
  if (dp[i][x] != -1) return dp[i][x];
  int ans = 0;
  ans = ans | solve(i + 1, x - a[i], a, dp);
  ans = ans | solve(i + 1, x + a[i], a, dp);
  return res = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l = 1;
    int r = 1501;
    long long res = 1501;
    while (l <= r) {
      mid = (r - l) / 2 + l;
      vector<vector<int> > dp(n, vector<int>(mid + 1, -1));
      bool flag = 0;
      for (int i = 0; i <= mid; i++) {
        flag = flag || solve(0, i, a, dp);
      }
      if (flag) {
        r = mid - 1;
        res = min(res, mid);
      } else {
        l = mid + 1;
      }
    }
    cout << res << '\n';
  }
}
