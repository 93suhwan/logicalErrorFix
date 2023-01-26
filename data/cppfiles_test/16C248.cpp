#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int n;
int a[N];
void solve() {
  vector<pair<int, int>> res;
  priority_queue<pair<int, int>> heap;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 0) heap.push({a[i], i});
  }
  while (heap.size() >= 2) {
    pair<int, int> a = heap.top();
    heap.pop();
    pair<int, int> b = heap.top();
    heap.pop();
    int an = a.first, bn = b.first;
    int c = 0;
    if (heap.size()) c = heap.top().first;
    while (an > 0 && bn > 0 && an >= c && bn >= c) {
      res.push_back({a.second, b.second});
      an--;
      bn--;
    }
    if (an > 0) heap.push({an, a.second});
    if (bn > 0) heap.push({bn, b.second});
  }
  cout << res.size() << endl;
  for (auto i : res) {
    cout << i.first << " " << i.second << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
