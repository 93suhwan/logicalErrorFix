#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
struct bad_hash {
  std::size_t operator()(const std::pair<int, int> &p) const {
    return p.first * 3000 + p.second;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &_ : (a)) cin >> _;
  if (n == 1) {
    cout << a[0] << "\n";
    return;
  }
  queue<pair<int, int> > q;
  q.push({a[0], 0});
  int ans = 2e9;
  for (int i = 1; i < n; i++) {
    unordered_map<int, int> diff_min;
    int mn = 1e9;
    while ((int)(q).size()) {
      auto [len, diff] = q.front();
      q.pop();
      diff = min(diff, len - diff);
      if (diff >= a[i]) {
        int ne = diff - a[i];
        ne = min(ne, len - ne);
        if (!((diff_min).count(ne) > 0)) {
          diff_min[ne] = len;
        } else {
          diff_min[ne] = min(diff_min[ne], len);
        }
        mn = min(mn, len);
      } else {
        if (!((diff_min).count(0) > 0)) {
          diff_min[0] = len + a[i] - diff;
        } else {
          diff_min[0] = min(diff_min[0], len + a[i] - diff);
        }
        mn = min(mn, len + a[i] - diff);
      }
      if (len - diff >= a[i]) {
        int ne = len - diff - a[i];
        ne = min(ne, len - ne);
        if (!((diff_min).count(ne) > 0)) {
          diff_min[ne] = len;
        } else {
          diff_min[ne] = min(diff_min[ne], len);
        }
        mn = min(mn, len);
      } else {
        if (!((diff_min).count(0) > 0)) {
          diff_min[0] = len;
        } else {
          diff_min[0] = min(diff_min[0], diff + a[i]);
        }
        mn = min(mn, diff + a[i]);
      }
    }
    if (i == n - 1) {
      ans = mn;
    } else {
      for (auto [a, b] : diff_min) {
        q.push({b, a});
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    solve();
  }
  return 0;
}
