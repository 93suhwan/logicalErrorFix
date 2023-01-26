#include <bits/stdc++.h>
using namespace std;
set<int> g[200005];
int intr[200005];
int f[200005];
set<int> tque;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = n;
  for (int i = 0; i < n + 1; i++) {
    g[i].clear();
    intr[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    g[x].insert(y);
    intr[y]++;
  }
  queue<int> que;
  for (int i = 1; i < n + 1; i++) {
    if (!intr[i]) {
      que.push(i);
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
      g[x].insert(y);
      intr[y]++;
      if (intr[y] == 1) {
        tque.erase(y);
      }
    } else if (sg == 2) {
      int x, y;
      cin >> x >> y;
      if (x > y) {
        swap(x, y);
      }
      g[x].erase(y);
      intr[y]--;
      if (intr[y] <= 0) {
        tque.insert(y);
      }
    } else {
      for (set<int>::iterator it = tque.begin(); it != tque.end(); it++) {
        int hd = *it;
        que.push(hd);
      }
      while (!que.empty()) {
        int hd = que.front();
        que.pop();
        if (intr[hd] > 0 || !g[hd].size()) {
          continue;
        }
        ans--;
        for (set<int>::iterator itr = g[hd].begin(); itr != g[hd].end();
             itr++) {
          int np = *itr;
          intr[np]--;
          if (intr[np] <= 0) {
            que.push(np);
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
