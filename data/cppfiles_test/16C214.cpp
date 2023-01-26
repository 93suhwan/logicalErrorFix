#include <bits/stdc++.h>
using std::pair;
const int maxn = 2e5 + 10;
int n, a[maxn], id[maxn];
std::vector<pair<int, int> > ans;
inline void solve() {
  std::priority_queue<pair<int, int> > q;
  ans.clear();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 0) continue;
    q.push(pair<int, int>(a[i], i));
  }
  pair<int, int> x, y;
  while (!q.empty()) {
    x = q.top();
    q.pop();
    if (q.empty()) break;
    y = q.top();
    q.pop();
    --x.first, --y.first;
    ans.push_back(pair<int, int>(x.second, y.second));
    if (x.first > 0) q.push(x);
    if (y.first > 0) q.push(y);
  }
  printf("%u\n", ans.size());
  for (pair<int, int> e : ans) printf("%d %d\n", e.first, e.second);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
