#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
inline void __run_test() {
  int n, m, k;
  cin >> n >> m >> k;
  vi x(n), y(m);
  vector<umii> xconf(n), yconf(m);
  for (int i = 0; i < (n); i++) cin >> x[i];
  for (int i = 0; i < (m); i++) cin >> y[i];
  for (int i = 0; i < (k); i++) {
    int xp, yp;
    cin >> xp >> yp;
    auto xx = binary_search((x).begin(), (x).end(), xp);
    auto yy = binary_search((y).begin(), (y).end(), yp);
    if (xx && yy) continue;
    if (xx)
      yconf[lower_bound((y).begin(), (y).end(), yp) - y.begin() - 1][xp]++;
    else
      xconf[lower_bound((x).begin(), (x).end(), xp) - x.begin() - 1][yp]++;
  }
  long long ans = 0;
  for (auto level : xconf) {
    int sum = 0;
    for (auto pp : level) {
      sum += pp.second;
      ans += 1LL * (sum - pp.second) * pp.second;
    }
  }
  for (auto level : yconf) {
    int sum = 0;
    for (auto pp : level) {
      sum += pp.second;
      ans += 1LL * (sum - pp.second) * pp.second;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __tests;
  cin >> __tests;
  while (__tests--) __run_test();
}
