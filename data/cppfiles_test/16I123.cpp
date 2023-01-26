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
    vv.insert({v[i], i + 1});
  }
  vector<pair<long long, long long>> res;
  while (vv.size() > 1) {
    auto x = vv.begin();
    vv.erase(x);
    auto y = vv.end();
    y--;
    vv.erase(y);
    long long z = min(x->first, y->first);
    pair<long long, long long> zz = {x->second, y->second};
    for (int i = 0; i < z; i++) {
      res.push_back(zz);
    }
    long long w = y->first - z;
    if (w) {
      vv.insert({w, y->second});
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
