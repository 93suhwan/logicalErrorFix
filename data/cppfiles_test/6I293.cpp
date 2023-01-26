#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int intr[200005];
int f[400005];
int to[400005];
int sz[200005];
queue<int> tque;
map<pair<int, int>, int> gg;
int main() {
  int n, m;
  cin >> n >> m;
  int cnt = m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
      swap(x, y);
    }
    g[x].push_back(i);
    ;
    sz[x]++;
    gg[make_pair(x, y)] = i;
    to[i] = y;
    intr[y]++;
  }
  queue<int> que;
  for (int i = 1; i < n + 1; i++) {
    if (!intr[i]) {
      tque.push(i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int sg;
    cin >> sg;
    if (sg == 1) {
      int x, y;
      cin >> x >> y;
      if (x > y) {
        swap(x, y);
      }
      g[x].push_back(cnt);
      ;
      sz[x]++;
      gg[make_pair(x, y)] = cnt;
      to[cnt++] = y;
      intr[y]++;
    } else if (sg == 2) {
      int x, y;
      cin >> x >> y;
      if (x > y) {
        swap(x, y);
      }
      f[gg[make_pair(x, y)]] = 1;
      sz[x]--;
      intr[y]--;
      if (intr[y] <= 0) {
        tque.push(y);
      }
    } else {
      int ans = n;
      queue<int> ttque;
      while (!tque.empty()) {
        int hd = tque.front();
        tque.pop();
        if (intr[hd] > 0 || !g[hd].size()) continue;
        que.push(hd);
      }
      while (!que.empty()) {
        int hd = que.front();
        que.pop();
        if (intr[hd] > 0 || !sz[hd]) {
          continue;
        }
        tque.push(hd);
        ans--;
        for (int i = 0; i < g[hd].size(); i++) {
          int np = g[hd][i];
          if (f[np]) continue;
          np = to[np];
          intr[np]--;
          ttque.push(np);
          if (intr[np] <= 0) {
            que.push(np);
          }
        }
      }
      while (!ttque.empty()) {
        int hd = ttque.front();
        ttque.pop();
        intr[hd]++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
