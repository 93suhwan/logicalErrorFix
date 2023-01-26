#include <bits/stdc++.h>
using namespace std;
int n, m;
int dis[4000010], col[4000010], co = 0;
char ch[2010];
int nxt[4000010];
stack<int> s, t;
void dfs(int u) {
  col[u] = co;
  s.push(u);
  if (nxt[u] == 0) {
    dis[u] = 1;
    return;
  }
  if (col[nxt[u]]) {
    if (col[nxt[u]] == co) {
      int num = 0;
      while (1) {
        int yy = s.top();
        s.pop();
        t.push(yy);
        num++;
        if (yy == nxt[u]) {
          break;
        }
      }
      while (!t.empty()) {
        dis[t.top()] = num;
        t.pop();
      }
      return;
    } else {
      dis[u] = dis[nxt[u]] + 1;
      return;
    }
  }
  dfs(nxt[u]);
  if (!dis[u]) dis[u] = dis[nxt[u]] + 1;
  return;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    while (!s.empty()) {
      s.pop();
    }
    while (!t.empty()) {
      t.pop();
    }
    for (int i = 1; i <= n * m; i++) {
      dis[i] = col[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch + 1);
      for (int j = 1; j <= m; j++) {
        if (ch[j] == 'L') {
          if (j == 1) {
            nxt[(i - 1) * m + j] = 0;
          } else {
            nxt[(i - 1) * m + j] = (i - 1) * m + j - 1;
          }
        }
        if (ch[j] == 'R') {
          if (j == m) {
            nxt[(i - 1) * m + j] = 0;
          } else {
            nxt[(i - 1) * m + j] = (i - 1) * m + j + 1;
          }
        }
        if (ch[j] == 'U') {
          if (i == 1) {
            nxt[(i - 1) * m + j] = 0;
          } else {
            nxt[(i - 1) * m + j] = (i - 2) * m + j;
          }
        }
        if (ch[j] == 'D') {
          if (i == n) {
            nxt[(i - 1) * m + j] = 0;
          } else {
            nxt[(i - 1) * m + j] = i * m + j;
          }
        }
      }
    }
    for (int i = 1; i <= n * m; i++) {
      if (!dis[i]) {
        ++co;
        dfs(i);
      }
    }
    int ans = 0, id = 0;
    for (int i = 1; i <= n * m; i++) {
      if (ans == 0 || ans < dis[i]) {
        ans = dis[i];
        id = i;
      }
    }
    printf("%d %d %d\n", m == 1 ? id : (id % m == 0 ? id / m : id / m + 1),
           (m == 1 ? 1 : (id % m == 0 ? m : id % m)), ans);
  }
  return 0;
}
