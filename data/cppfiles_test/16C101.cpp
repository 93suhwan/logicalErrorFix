#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  set<pair<long long, long long>> vv;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] > 0) {
      vv.insert({v[i], i + 1});
    }
  }
  vector<pair<long long, long long>> res;
  while (vv.size() > 1) {
    auto x = vv.begin();
    auto y = prev(vv.end());
    long long xf = x->first, xs = x->second;
    long long yf = y->first, ys = y->second;
    res.push_back({xs, ys});
    vv.erase(x);
    vv.erase(y);
    yf--;
    xf--;
    if (yf > 0) {
      vv.insert({yf, ys});
    }
    if (xf > 0) {
      vv.insert({xf, xs});
    }
  }
  cout << res.size() << '\n';
  for (auto u : res) {
    cout << u.first << ' ' << u.second << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
