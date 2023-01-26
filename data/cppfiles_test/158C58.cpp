#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
long long __pow(long long x, long long y, long long M) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long __pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
long long mi(long long x, long long M) { return __pow(x, M - 2, M); }
long long mul(vector<long long> a, long long M) {
  long long res = 1;
  for (auto x : a) res = (res * x) % M;
  return res;
}
long long cl(long long a, long long b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
void umax(long long &a, long long b) { a = max(a, b); }
void umin(long long &a, long long b) { a = min(a, b); }
const long long N = 10 + 2, inf = 1e18, M = 1e9 + 7, LN = 20;
long long Test, n, m, k, q, a[N];
bool ok = 1;
string s[N];
void test_case() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> s[i];
  long long mx = -inf;
  vector<long long> mxv(m);
  for (long long b = 0; b < (1ll << n); b++) {
    long long res = 0;
    for (long long i = 0; i < n; i++) {
      if (b & (1ll << i))
        res -= a[i];
      else
        res += a[i];
    }
    vector<pair<long long, long long>> t(m);
    for (long long j = 0; j < m; j++) {
      t[j].second = j;
      for (long long i = 0; i < n; i++) {
        if (b & (1ll << i))
          t[j].first += (s[i][j] - '0');
        else
          t[j].first -= (s[i][j] - '0');
      }
    }
    sort((t).begin(), (t).end());
    for (long long i = 0; i < m; i++) res += t[i].first * (i + 1);
    if (mx < res) {
      mx = res;
      for (long long i = 0; i < m; i++) mxv[t[i].second] = i + 1;
    }
  }
  debug() << " ["
          << "mx"
             ": "
          << (mx) << "] ";
  for (auto x : mxv) cout << x << " ";
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Test = 1;
  cin >> Test;
  for (long long t = 1; t <= Test; t++) {
    test_case();
  }
  return 0;
}
