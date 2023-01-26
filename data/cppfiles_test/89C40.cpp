#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
const int N = 200010;
int n;
int c1, c2;
std::vector<int> e[N];
int dfs(int u, int f) {
  int c = 0;
  for (auto v : e[u])
    if (v != f) c += dfs(v, u);
  if (c) {
    c1++;
    c2 += c;
    return 0;
  } else
    return 1;
}
int main() {
  for (int T = (1), end_T = (read()); T <= end_T; T++) {
    n = read();
    c1 = c2 = 0;
    for (int i = (1), end_i = (n); i <= end_i; i++) e[i].clear();
    for (int i = (1), end_i = (n - 1); i <= end_i; i++) {
      int u = read(), v = read();
      e[u].push_back(v);
      e[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", c2 - (c1 - 1));
  }
  return 0;
}
