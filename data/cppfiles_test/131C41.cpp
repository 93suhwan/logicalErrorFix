#include <bits/stdc++.h>
using namespace std;
int a[200000 + 5];
map<int, pair<pair<int, int>, pair<int, int> > > s;
priority_queue<int> Q;
int fa(int x) {
  int y = 1;
  while (y < x) y <<= 1;
  return y - x;
}
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    Q.push(a[i]);
    s[a[i]].first = make_pair(0, i);
  }
  while (!Q.empty()) {
    int u = Q.top();
    Q.pop();
    if (!Q.empty() && Q.top() == u) continue;
    if (u) {
      int v = fa(u);
      Q.push(v);
      pair<int, int> now = s[u].first;
      now.first++;
      if (s[v].first < now)
        s[v].second = s[v].first, s[v].first = now;
      else if (s[v].second < now)
        s[v].second = now;
    }
  }
  map<int, pair<pair<int, int>, pair<int, int> > >::iterator it = s.begin();
  int x = 0, y = 0, ans = -1;
  while (it != s.end()) {
    pair<pair<int, int>, pair<int, int> > now = it->second;
    if (now.first.second && now.second.second) {
      if (now.first.first + now.second.first > ans) {
        ans = now.first.first + now.second.first;
        x = now.first.second;
        y = now.second.second;
      }
    }
    it++;
  }
  printf("%d %d %d\n", x, y, ans);
}
