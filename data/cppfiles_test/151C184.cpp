#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
constexpr int N = 2e5 + 7;
constexpr int M = 998244353;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long q;
  cin >> q;
  vector<tuple<long long, long long, long long>> a(q);
  for (auto& [op, x, y] : a) {
    cin >> op >> x;
    if (op == 2) cin >> y;
  }
  vector<long long> ans;
  map<long long, long long> t;
  reverse(a.begin(), a.end());
  for (auto& [op, x, y] : a) {
    if (op == 1) {
      if (t.count(x)) {
        ans.emplace_back(t[x]);
      } else {
        ans.emplace_back(x);
      }
    } else {
      if (t.count(y)) {
        t[x] = t[y];
      } else {
        t[x] = y;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}
#pragma clang diagnostic pop
