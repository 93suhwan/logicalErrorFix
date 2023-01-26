#include <bits/stdc++.h>
using namespace std;
const string alp = "abcdefghijklmnopqrstuvwxyz";
void solve() {
  int n;
  cin >> n;
  vector<string> w(n);
  unordered_map<char, vector<int>> v;
  unordered_map<char, int> cnt;
  for (auto &xx : (w)) cin >> xx;
  ;
  for (auto c : {'a', 'b', 'c', 'd', 'e'}) {
    cnt[c] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (auto c : {'a', 'b', 'c', 'd', 'e'}) {
      int cx = count(begin(w[i]), end(w[i]), c);
      cnt[c] += cx;
      v[c].push_back(cx * 2 - w[i].size());
    }
  }
  int res = 0;
  for (auto c : {'a', 'b', 'c', 'd', 'e'}) {
    sort(begin(v[c]), end(v[c]));
  }
  for (auto c : {'a', 'b', 'c', 'd', 'e'}) {
    auto &x = v[c];
    int wc = n;
    int sum = cnt[c] * 2;
    for (auto cx : {'a', 'b', 'c', 'd', 'e'}) sum -= cnt[cx];
    if (sum < 1) {
      auto it = x.begin();
      do {
        sum -= *it;
        wc--;
        if (sum > 0) break;
        it++;
      } while (it != x.end());
      if (wc != 0) res = max(res, wc);
    } else {
      res = n;
    }
  }
  cout << (res) << '\n';
  ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(12) << fixed;
  int t = 1;
  cin >> t;
  while (t--) solve();
  cout.flush();
  return 0;
}
