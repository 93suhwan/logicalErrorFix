#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > ans;
  priority_queue<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    q.push({c, i + 1});
  }
  while (1) {
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();
    if (b.first == 0) break;
    ans.push_back({a.second, b.second});
    q.push({a.first - 1, a.second});
    q.push({b.first - 1, b.second});
  }
  cout << ans.size() << "\n";
  for (auto l : ans) cout << l.first << " " << l.second << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
