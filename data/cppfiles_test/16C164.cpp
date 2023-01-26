#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int> > q;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 0) continue;
    q.push({x, i});
  }
  vector<pair<int, int> > v;
  int cnt = 0;
  while (1) {
    if (q.size() < 2) break;
    int x1 = q.top().first;
    int a1 = q.top().second;
    q.pop();
    int x2 = q.top().first;
    int a2 = q.top().second;
    q.pop();
    v.push_back({a2, a1});
    x1--;
    x2--;
    if (x1) q.push({x1, a1});
    if (x2) q.push({x2, a2});
    cnt++;
  }
  cout << cnt << endl;
  for (auto &i : v) {
    cout << i.first << " " << i.second << endl;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
