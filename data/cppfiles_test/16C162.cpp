#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
void gogo() {
  int64_t n;
  cin >> n;
  max_heap<pair<int64_t, int64_t>> q;
  for (int64_t i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    q.push({x, i});
  }
  vector<pair<int64_t, int64_t>> ans;
  while (!q.empty()) {
    auto [x, i1] = q.top();
    q.pop();
    if (q.empty()) break;
    auto [y, i2] = q.top();
    q.pop();
    if (x > 0 && y > 0) ans.push_back({i1 + 1, i2 + 1});
    x--, y--;
    if (x > 0) q.push({x, i1});
    if (y > 0) q.push({y, i2});
  }
  cout << int64_t(ans.size()) << "\n";
  for (auto &[x, y] : ans) {
    cout << x << ' ' << y << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t tc = 1;
  cin >> tc;
  while (tc--) gogo();
  return 0;
}
