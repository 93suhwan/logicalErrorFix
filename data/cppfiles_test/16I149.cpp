#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < n; ++i) {
    int cnt;
    cin >> cnt;
    if (cnt != 0) pq.push({cnt, i});
  }
  vector<pair<int, int> > ans;
  while (pq.size() >= 2) {
    pair<int, int> a = pq.top();
    pq.pop();
    pair<int, int> b = pq.top();
    pq.pop();
    for (int i = 0; i < b.first; ++i) {
      ans.push_back({a.second + 1, b.second + 1});
    }
    a.first -= b.first;
    if (a.first > 0) {
      pq.push(a);
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
