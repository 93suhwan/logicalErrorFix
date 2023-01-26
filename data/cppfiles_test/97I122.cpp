#include <bits/stdc++.h>
using namespace std;
template <typename Ta, typename Tb>
ostream &operator<<(ostream &os, pair<Ta, Tb> x) {
  return os << x.first << " " << x.second;
}
char s[501][501];
vector<int> c[512 * 512];
bitset<512 * 512> odw, col;
bool marked(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return s[x][y] == 'X';
}
int marked_ct(int i, int j) {
  return marked(i - 1, j) + marked(i + 1, j) + marked(i, j - 1) +
         marked(i, j + 1);
}
void check_odd(int n, int m) {
  for (int i = (int)0; i < (int)n; ++i)
    for (int j = (int)0; j < (int)m; ++j)
      if (marked(i, j)) {
        int sum = marked_ct(i, j);
        if (sum & 1) {
          puts("NO");
          exit(0);
        }
      }
}
void check_for_add_edge(int x, int y, pair<int, int> &a, pair<int, int> &b) {
  pair<int, int> base = make_pair(-1, -1);
  if (!marked(x, y) && x >= 0 && y >= 0) {
    if (a == base)
      a = make_pair(x, y);
    else
      b = make_pair(x, y);
  }
}
int vert(pair<int, int> x) { return (x.first << 9) + x.second; }
pair<int, int> wsp(int x) { return make_pair(x >> 9, x - (x >> 9)); }
void add_edge(int x, int y, bool rev = 0) {
  pair<int, int> a, b, cc;
  a = b = cc = make_pair(-1, -1);
  if (rev == 0) {
    if (!marked(x - 1, y) && x >= 0) a = make_pair(x - 1, y);
    check_for_add_edge(x, y + 1, a, b);
    check_for_add_edge(x + 1, y, a, b);
    check_for_add_edge(x, y - 1, a, b);
  } else {
    if (!marked(x, y - 1) && x >= 0) a = make_pair(x, y - 1);
    check_for_add_edge(x + 1, y, a, b);
    check_for_add_edge(x, y + 1, cc, b);
    c[vert(cc)].push_back(vert(a));
    c[vert(cc)].push_back(vert(b));
    c[vert(a)].push_back(vert(cc));
    c[vert(b)].push_back(vert(cc));
  }
  c[vert(a)].push_back(vert(b));
  c[vert(b)].push_back(vert(a));
}
void build(int n, int m) {
  for (int i = (int)0; i < (int)n; ++i)
    for (int j = (int)0; j < (int)m; ++j) {
      if (marked(i, j) && marked_ct(i, j) == 2) add_edge(i, j);
      if (marked(i, j) && marked_ct(i, j) == 0)
        add_edge(i, j), add_edge(i, j, 1);
    }
}
void dfs(int x, bool color) {
  odw[x] = 1;
  col[x] = color;
  for (auto ss : c[x])
    if (!odw[ss]) dfs(ss, color ^ 1);
}
void solve(int n, int m) {
  for (int i = (int)0; i < (int)n; ++i)
    for (int j = (int)0; j < (int)m; ++j)
      if (!odw[vert(make_pair(i, j))] && !marked(i, j))
        dfs(vert(make_pair(i, j)), 1);
}
void print(int n, int m) {
  puts("YES");
  for (int i = (int)0; i < (int)n; ++i) {
    for (int j = (int)0; j < (int)m; ++j) {
      if (!marked(i, j))
        printf("%d ", col[vert(make_pair(i, j))] ? 4 : 1);
      else
        printf("%d ", (4 - marked_ct(i, j)) * 5 / 2);
    }
    puts("");
  }
}
void solve(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (int)0; i < (int)n; ++i) scanf("%s", s[i]);
  check_odd(n, m);
  build(n, m);
  solve(n, m);
  print(n, m);
}
int32_t main(void) {
  int t;
  t = 1;
  while (t--) solve();
}
