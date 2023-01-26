#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 2010;
int n;
char s[N];
inline void GG() {
  puts("NONE");
  exit(0);
}
int id[N][N];
vector<pair<int, int> > e[N * N];
inline void Add(int x1, int y1, int x2, int y2, int c) {
  e[id[x1][y1]].emplace_back(id[x2][y2], c);
  e[id[x2][y2]].emplace_back(id[x1][y1], c);
}
inline void Build() {
  int x1 = 1, y1 = 2, x2 = 2, y2 = 1;
  for (int i = (1); i < (n); i++) {
    Add(x1, y1, x2, y2, 0);
    if (x1 < n && y1 < n) Add(x1, y1, x1 + 1, y1 + 1, 1);
    if (x2 < n && y2 < n) Add(x2, y2, x2 + 1, y2 + 1, 1);
    ++x1, ++y1, ++x2, ++y2;
  }
  for (int i = (1); i <= (n); i++)
    if (i % 2) {
      Add(1, i, 1, i + 1, 0);
      Add(i, 1, i + 1, 1, 0);
    }
  for (int i = (4); i <= (n); i++)
    if (i % 2 == 0) {
      int x = 1, y = i;
      while (x < n && y < n) {
        Add(x, y, x + 1, y + 1, 1);
        x++, y++;
      }
      x = i, y = 1;
      while (x < n && y < n) {
        Add(x, y, x + 1, y + 1, 1);
        x++, y++;
      }
    }
}
inline int get(char c) {
  if (c == '.') return -1;
  return c == 'S';
}
int cnt[2][2], bel[N * N], tot;
short vis[N * N], c[N * N], g[N * N];
bool flag;
inline void dfs(int u, int d) {
  queue<int> q;
  q.push(u), vis[u] = d, bel[u] = tot;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (c[u] != -1) cnt[vis[u]][c[u]]++, flag = 1;
    for (auto [v, w] : e[u])
      if (vis[v] == -1)
        vis[v] = vis[u] ^ w, bel[v] = tot, q.push(v);
      else if (vis[v] != (vis[u] ^ w))
        GG();
  }
}
int main() {
  n = read();
  if (n & 1) GG();
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s + 1);
    for (int j = (1); j <= (n); j++)
      id[i][j] = (i - 1) * n + j, c[id[i][j]] = get(s[j]);
  }
  Build();
  for (int i = (1); i <= (n); i++) reverse(id[i] + 1, id[i] + 1 + n);
  Build();
  memset((vis), (-1), sizeof(vis));
  bool f = 0;
  for (int i = (1); i <= (n * n); i++)
    if (vis[i] == -1) {
      for (int j = (0); j <= (1); j++)
        for (int k = (0); k <= (1); k++) cnt[j][k] = 0;
      flag = 0, ++tot, dfs(i, 0);
      if (cnt[0][0] && cnt[0][1]) GG();
      if (cnt[1][0] && cnt[1][1]) GG();
      if (cnt[0][1] && cnt[1][1]) GG();
      if (cnt[0][0] && cnt[1][0]) GG();
      if (!flag) f = 1;
      g[tot] = cnt[0][1] || cnt[1][0];
    }
  if (f) return puts("MULTIPLE"), 0;
  puts("UNIQUE");
  for (int i = (1); i <= (n); i++) {
    reverse(id[i] + 1, id[i] + 1 + n);
    for (int j = (1); j <= (n); j++)
      putchar(vis[id[i][j]] ^ g[bel[id[i][j]]] ? 'S' : 'G');
    puts("");
  }
}
