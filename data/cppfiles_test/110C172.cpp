#include <bits/stdc++.h>
using namespace std;
int T;
int d[200005];
int head[200005], net[2000005], v[2000000];
int tot = 0;
int n;
int num = 1;
int rans = 0;
priority_queue<int, deque<int>, greater<int> > q;
priority_queue<int, deque<int>, greater<int> > q2;
void add(int x, int y) { tot++, v[tot] = y, net[tot] = head[x], head[x] = tot; }
void init() {
  rans = 0;
  num = n;
  tot = 0;
  while (q2.size()) q2.pop();
  for (int i = 1; i <= n; i++) {
    d[i] = head[i] = 0;
  }
}
void bfs() {
  while (q.size()) {
    rans++;
    int lst = 0;
    while (q.size()) {
      int x = q.top();
      q.pop();
      if (lst > x) {
        q2.push(x);
      } else {
        lst = x;
        for (int i = head[x]; i; i = net[i]) {
          int y = v[i];
          d[y]--;
          if (!d[y]) q.push(y), num--;
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
      if (d[i] == 0) q.push(i), num--;
    }
    bfs();
    if (num) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", rans);
  }
  return 0;
}
