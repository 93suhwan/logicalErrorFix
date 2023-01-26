#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, bool> xok, yok;
  vector<int> xlmt, ylmt;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    xlmt.push_back(x);
    xok[x] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int y;
    cin >> y;
    ylmt.push_back(y);
    yok[y] = 1;
  }
  vector<pair<int, int>> X, Y;
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (xok[x] && yok[y]) continue;
    if (yok[y])
      Y.push_back({x, y});
    else
      X.push_back({x, y});
  }
  sort(X.begin(), X.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
  sort(Y.begin(), Y.end());
  reverse(Y.begin(), Y.end());
  long long ans = 0;
  for (int lmt : ylmt) {
    vector<pair<int, int>> resev;
    while (!X.empty()) {
      if (X.back().second < lmt) {
        resev.push_back(X.back());
        X.pop_back();
        continue;
      }
      break;
    }
    if (resev.empty()) continue;
    map<int, int> cnt;
    for (auto [x, y] : resev) {
      cnt[x]++;
    }
    long long res = 0, sum = 0;
    for (auto [x, y] : cnt) {
      res += (sum * y);
      sum += y;
    }
    ans += res;
  }
  for (int lmt : xlmt) {
    vector<pair<int, int>> resev;
    while (!Y.empty()) {
      if (Y.back().first < lmt) {
        resev.push_back(Y.back());
        Y.pop_back();
        continue;
      }
      break;
    }
    if (resev.empty()) continue;
    map<int, int> cnt;
    for (auto [x, y] : resev) {
      cnt[y]++;
    }
    long long res = 0, sum = 0;
    for (auto [x, y] : cnt) {
      res += (sum * y);
      sum += y;
    }
    ans += res;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
