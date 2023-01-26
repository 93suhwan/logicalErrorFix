#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
void solve() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
      q;
  vector<pair<int, int>> res;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) q.push({x, i});
  }
  while (q.top().first && q.size() > 1) {
    int x = q.top().first;
    int index_x = q.top().second;
    q.pop();
    int y = q.top().first;
    int index_y = q.top().second;
    q.pop();
    x--, y--;
    res.push_back({index_x, index_y});
    if (x > 0) q.push({x, index_x});
    if (y > 0) q.push({y, index_y});
  }
  cout << res.size() << '\n';
  if (res.size()) {
    for (int i = 0; i < res.size(); i++)
      cout << res[i].first << " " << res[i].second << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
