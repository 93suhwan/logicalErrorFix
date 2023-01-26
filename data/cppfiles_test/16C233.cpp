#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x != 0) pq.push({x, i});
  }
  while (!pq.empty()) {
    pair<int, int> a = pq.top();
    pq.pop();
    if (pq.empty()) break;
    pair<int, int> b = pq.top();
    pq.pop();
    ans.push_back({a.second, b.second});
    a.first--;
    if (a.first) pq.push(a);
    b.first--;
    if (b.first) pq.push(b);
  }
  cout << ans.size() << "\n";
  for (auto elem : ans) {
    cout << elem.first << " " << elem.second << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
