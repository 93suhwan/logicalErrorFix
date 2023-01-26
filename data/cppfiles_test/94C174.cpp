#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n), ans(10);
  for (int& u : s) cin >> u;
  ans[0] = k + 1;
  for (int i = 0; i < s.size() - 1; i++) {
    int step = s[i + 1] - s[i];
    int64_t mx = 1LL;
    for (int j = 0; j < step; j++) mx *= 10;
    if (mx <= ans[s[i]]) {
      ans[s[i + 1]] = ans[s[i]] - mx + 1;
      ans[s[i]] = mx - 1;
    }
  }
  int64_t res = 0, mod = 1;
  for (int i = 0; i < 10; i++) {
    res += mod * ans[i];
    mod *= 10;
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
