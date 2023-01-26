#include <bits/stdc++.h>
using namespace std;
long long mod(long long x, long long MOD) {
  if (x > MOD) x -= MOD;
  return x;
}
long long _ceil(long long x, long long y) { return x / y + (x % y != 0); }
void wrt() {
  cout << "\n";
  return;
}
template <typename T1, typename... T2>
void wrt(T1 x, T2... args) {
  ((cout << x << ' '), wrt(args...));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& i : v) os << i << " ";
  return os;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& e : v) in >> e;
  return in;
}
const long long MOD = 998244353;
const long long N = 1e6 + 5, inf = 1e18 + 2;
long long n, m, x, u, v, k, p, q, i, j;
string s, t;
long long ans;
long long a[N];
void solve() {
  cin >> n >> k;
  vector<long long> x, y;
  for (long long i = 0; i < (n); ++i) {
    cin >> u;
    if (u > 0) x.push_back(u);
    if (u < 0) y.push_back(-u);
  }
  x.push_back(0), y.push_back(0);
  sort((x).begin(), (x).end());
  sort((y).begin(), (y).end());
  ans = 0;
  if (x.back() > y.back()) {
    while (!y.empty()) {
      u = k;
      ans += 2 * y.back();
      while (u-- && !y.empty()) y.pop_back();
    }
    u = k;
    ans += x.back();
    while (u-- && !x.empty()) x.pop_back();
    while (!x.empty()) {
      u = k;
      ans += 2 * x.back();
      while (u-- && !x.empty()) x.pop_back();
    }
  } else {
    while (!x.empty()) {
      u = k;
      ans += 2 * x.back();
      while (u-- && !x.empty()) x.pop_back();
    }
    u = k;
    ans += y.back();
    while (u-- && !y.empty()) y.pop_back();
    while (!y.empty()) {
      u = k;
      ans += 2 * y.back();
      while (u-- && !y.empty()) y.pop_back();
    }
  }
  wrt(ans);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
