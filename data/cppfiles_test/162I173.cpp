#include <bits/stdc++.h>
using namespace std;
pair<int64_t, bool> check(int64_t x, vector<int64_t>& orig) {
  vector<int64_t> a = orig;
  for (int64_t i = a.size() - 1; i >= 2; i--) {
    int64_t giveOn = min(orig[i], a[i] - x);
    int64_t d = giveOn / 3;
    a[i] -= d * 3;
    a[i - 1] += d;
    a[i - 2] += d * 2;
  }
  return {*min_element(a.begin(), a.end()),
          *min_element(a.begin(), a.end()) == a.back()};
}
void solve() {
  int64_t n;
  cin >> n;
  vector<int64_t> a;
  for (int64_t i = 0; i < n; i++) {
    int64_t tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  int64_t l = 0;
  int64_t r = a.back();
  while (l != r) {
    int64_t m = (l + r + 1) / 2;
    if (check(m, a).second)
      l = m;
    else
      r = m - 1;
  }
  cout << max(max(check(l - 1, a).first, check(l, a).first),
              check(l + 1, a).first)
       << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t t;
  cin >> t;
  for (int64_t tc = 0; tc < t; tc++) {
    solve();
  }
  return 0;
}
