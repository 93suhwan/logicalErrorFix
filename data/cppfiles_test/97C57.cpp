#include <bits/stdc++.h>
constexpr int N = 505;
int n, m;
std::string s;
bool a[N][N];
int ans[N][N];
int f[N * N];
std::vector<int> v[N * N];
int point(int x, int y) { return (x - 1) * m + y; }
std::pair<int, int> pos(int x) {
  return std::make_pair((x - 1) / m + 1, (x - 1) % m + 1);
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  f[x] = y;
}
int cnt(int x, int y) {
  return !a[x - 1][y] + !a[x][y - 1] + !a[x + 1][y] + !a[x][y + 1];
}
void add(int x, int y) { v[x].push_back(y), v[y].push_back(x); }
void dfs(int x, int y, int now) {
  ans[x][y] = now ? 1 : 4;
  for (int i : v[point(x, y)])
    if (!ans[pos(i).first][pos(i).second])
      dfs(pos(i).first, pos(i).second, now ^ 1);
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> s;
    for (int j = 1; j <= m; ++j) a[i][j] = s[j - 1] == 'X';
  }
  std::iota(f + 1, f + n * m + 1, 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j]) {
        int x = cnt(i, j);
        if (x & 1) return std::cout << "NO\n", 0;
        if (x == 4)
          merge(point(i - 1, j), point(i + 1, j)),
              merge(point(i, j - 1), point(i, j + 1));
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j]) {
        int x = cnt(i, j);
        if (x == 4)
          add(find(point(i - 1, j)), find(point(i, j - 1)));
        else if (x == 2) {
          std::vector<int> v;
          if (!a[i - 1][j]) v.push_back(point(i - 1, j));
          if (!a[i + 1][j]) v.push_back(point(i + 1, j));
          if (!a[i][j - 1]) v.push_back(point(i, j - 1));
          if (!a[i][j + 1]) v.push_back(point(i, j + 1));
          add(find(v.front()), find(v.back()));
        }
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (!a[i][j] && !ans[i][j] && find(point(i, j)) == point(i, j))
        dfs(i, j, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (!a[i][j]) {
        int x = find(point(i, j));
        ans[i][j] = ans[pos(x).first][pos(x).second];
      }
  std::cout << "YES\n";
  for (int i = 1; i <= n; ++i, std::cout << '\n')
    for (int j = 1; j <= m; ++j)
      if (a[i][j])
        std::cout << !a[i - 1][j] * ans[i - 1][j] +
                         !a[i][j - 1] * ans[i][j - 1] +
                         !a[i + 1][j] * ans[i + 1][j] +
                         !a[i][j + 1] * ans[i][j + 1]
                  << ' ';
      else
        std::cout << ans[i][j] << ' ';
  return 0;
}
