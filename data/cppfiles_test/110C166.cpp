#include <bits/stdc++.h>
using namespace std;
int T;
int d[200005];
int head[200005], net[2000005], v[2000000];
int vis[200005];
int tot = 0;
int cnt = 0;
int n;
int f = 1;
int ans[200005];
int rans = 0;
priority_queue<int, deque<int>, greater<int> > q;
priority_queue<int, deque<int>, greater<int> > q2;
void add(int x, int y) { tot++, v[tot] = y, net[tot] = head[x], head[x] = tot; }
void init() {
  f = 1;
  tot = 0;
  cnt = 0;
  while (q2.size()) q2.pop();
  for (int i = 1; i <= n; i++) {
    d[i] = head[i] = vis[i] = 0;
  }
}
void dfs() {
  while (q.size()) {
    rans++;
    int lst = 0;
    while (q.size()) {
      int p = q.top();
      vis[p] = 1;
      q.pop();
      if (lst > p) {
        q2.push(p);
      } else {
        lst = p;
        for (int i = head[p]; i; i = net[i]) {
          int y = v[i];
          d[y]--;
          if (!d[y]) q.push(y);
        }
      }
    }
    if (q2.size()) {
      swap(q, q2);
    }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    init();
    rans = 0;
    for (int i = 1; i <= n; i++) {
      int t;
      scanf("%d", &t);
      for (int j = 1; j <= t; j++) {
        int t1;
        scanf("%d", &t1);
        add(t1, i);
        d[i]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (d[i] == 0) q.push(i);
    }
    dfs();
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) f = 0;
    }
    if (!f) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", rans);
  }
  return 0;
}
