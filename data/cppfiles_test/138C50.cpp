#include <bits/stdc++.h>
using namespace std;
int i, j, k, t, n, m, fa[500500], it, a[500500], b[500500];
long long res[500500], sum, ans, pre[500500];
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
struct SB {
  int w, cl, cr, sb;
  bool operator<(const SB x) const { return w < x.w; }
} s[500500];
set<pair<int, int> > q;
priority_queue<pair<int, int> > ev;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> t;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    s[++it] = {a[i], 0, 0, 1};
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    s[++it] = {b[i], 0, 0, 0};
  }
  for (i = 1; i <= t; i++) {
    cin >> k;
    q.insert({k, i});
  }
  sort(s + 1, s + it + 1);
  for (i = 1; i <= it; i++) {
    fa[i] = i;
    pre[i] = pre[i - 1] + s[i].w;
    if (s[i].sb) {
      ans += s[i].w;
      s[i].cl = s[i].cr = i;
    } else {
      s[i].cl = i + 1;
      s[i].cr = i;
    }
    if (i != it) ev.push({s[i].w - s[i + 1].w, i});
  }
  for (auto [i, j] : q) {
    while (!ev.empty()) {
      auto [x, y] = ev.top();
      x = -x;
      if ((x > i)) break;
      ev.pop();
      if (find(y) == find(y + 1)) continue;
      x = find(y);
      y = find(y + 1);
      fa[x] = y;
      ans -= pre[s[y].cr] - pre[s[y].cl - 1];
      ans -= pre[s[x].cr] - pre[s[x].cl - 1];
      s[y].cl -= s[x].sb;
      s[y].sb += s[x].sb;
      ans += pre[s[y].cr] - pre[s[y].cl - 1];
    }
    res[j] = ans;
  }
  for (i = 1; i <= t; i++) cout << res[i] << '\n';
}
