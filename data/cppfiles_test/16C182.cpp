#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > 0) pq.push({tmp, i + 1});
  }
  vector<pair<int, int>> ans;
  while ((int)(pq.size()) > 1) {
    auto a = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();
    ans.push_back({a.second, b.second});
    if (a.first - 1 > 0) pq.push({a.first - 1, a.second});
    if (b.first - 1 > 0) pq.push({b.first - 1, b.second});
  }
  cout << (int)ans.size() << '\n';
  for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
