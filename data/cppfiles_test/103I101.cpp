#include <bits/stdc++.h>
using namespace std;
const int N = 2100, M = 4 * 1e6 + 100;
int t, n, m, f[M], cir[M], vi[M], w, de[N];
char s[N][N];
vector<int> e[M], p[M];
int id(int x, int y) { return (x - 1) * m + y; }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void dfs(int x) {
  for (int u : e[x]) {
    de[u] = de[x] + 1;
    dfs(u);
  }
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c = s[i][j];
        int x = i, y = j;
        if (c == 'L') y--;
        if (c == 'R') y++;
        if (c == 'U') x--;
        if (c == 'D') x++;
        if (x <= 0 || y <= 0 || x > n || y > m) {
          f[id(i, j)] = id(i, j);
          continue;
        }
        f[id(i, j)] = id(x, y);
      }
    int k = n * m;
    for (int i = 1; i <= k; i++)
      vi[i] = cir[i] = de[i] = 0, e[i].clear(), p[i].clear();
    w = 0;
    for (int i = 1; i <= k; i++)
      if (!vi[i]) {
        stack<int> st;
        int x = i;
        st.push(x);
        vi[x] = i;
        while (1) {
          x = f[x];
          if (vi[x]) {
            if (vi[x] != i) break;
            w++;
            while (st.top() != x) p[w].push_back(st.top()), st.pop();
            p[w].push_back(x);
            break;
          }
          vi[x] = i;
          st.push(x);
        }
      }
    for (int i = 1; i <= w; i++)
      for (int j : p[i]) cir[j] = i;
    for (int i = 1; i <= k; i++)
      if (!cir[i]) e[f[i]].push_back(i);
    for (int i = 1; i <= k; i++)
      if (!de[i]) {
        de[i] = (int)p[cir[i]].size();
        dfs(i);
      }
    int pos = max_element(de + 1, de + 1 + k) - de;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (id(i, j) == pos) {
          printf("%d %d %d\n", i, j, de[pos]);
        }
  }
}
