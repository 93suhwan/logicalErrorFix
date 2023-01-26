#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
long double pi = 3.141592653589793238462643383279;
const long long INF = 1e18 + 10;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mod = 998244353;
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void bruteforce() {}
void init() {}
const long long mxN = 1e5 + 10;
void solve() {
  long long q;
  cin >> q;
  vector<pair<long long, pair<long long, long long>>> v;
  for (long long i = 0; i < q; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x;
      cin >> x;
      v.push_back({1, {x, 0}});
    } else {
      long long x, y;
      cin >> x >> y;
      v.push_back({2, {x, y}});
    }
  }
  reverse(v.begin(), v.end());
  map<long long, long long> active;
  for (long long i = 1; i <= 5e5; i++) {
    active[i] = i;
  }
  vector<long long> ans;
  for (long long i = 0; i < q; i++) {
    long long t = v[i].first;
    if (t == 1) {
      long long x = v[i].second.first;
      ans.push_back(active[x]);
    } else {
      long long x = v[i].second.first;
      long long y = v[i].second.second;
      active[x] = active[y];
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long x : ans) {
    cout << x << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T = 1;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
}
