#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 2000;
int n;
char g[MAXN][MAXN + 1];
char ans[MAXN][MAXN + 1];
int pat[MAXN][MAXN];
int solve() {
  if (n % 2 != 0) return 0;
  auto assign = [&](int x, int y, int val) {
    assert(val != -1 && pat[x][y] == -1 || pat[x][y] == val);
    pat[x][y] = val;
  };
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) pat[i][j] = -1;
  for (int i = (0); i < (n); ++i) assign(i, 0, i / 2 * 2);
  for (int i = (0); i < (n); ++i)
    if (i % 2 == 0)
      for (int j = 1; i - j >= 0; ++j) assign(i - j, j, pat[i][0] ^ (j & 1));
  for (int i = (0); i < (n); ++i)
    if (i % 2 == 1)
      for (int j = 1; i + j < n; ++j) assign(i + j, j, pat[i][0] ^ (j & 1));
  for (int j = (0); j < (n); ++j)
    if (j % 2 == 0) assign(0, j + 1, pat[0][j]);
  for (int j = (0); j < (n); ++j)
    if (j % 2 == 1)
      for (int i = 1; i + j < n; ++i) assign(i, i + j, pat[0][j] ^ (i & 1));
  for (int j = (0); j < (n); ++j)
    if (j % 2 == 0) assign(n - 1, j + 1, pat[n - 1][j]);
  for (int j = (0); j < (n); ++j)
    if (j % 2 == 1)
      for (int i = 1; i + j < n; ++i)
        assign(n - 1 - i, i + j, pat[n - 1][j] ^ (i & 1));
  vector<int> val(n / 2, -1);
  for (int x = (0); x < (n); ++x)
    for (int y = (0); y < (n); ++y)
      if (g[x][y] != '.') {
        int v = g[x][y] == 'G' ? 0 : 1;
        v ^= pat[x][y] & 1;
        int id = pat[x][y] / 2;
        if (val[id] != -1 && val[id] != v) return 0;
        val[id] = v;
      }
  for (int id = (0); id < (n / 2); ++id)
    if (val[id] == -1) return 2;
  for (int x = (0); x < (n); ++x)
    for (int y = (0); y < (n); ++y)
      ans[x][y] = (val[pat[x][y] / 2] ^ (pat[x][y] & 1)) == 0 ? 'G' : 'S';
  for (int x = (0); x < (n); ++x) ans[x][n] = '\0';
  return 1;
}
void run() {
  scanf("%d", &n);
  for (int x = (0); x < (n); ++x) scanf("%s", g[x]);
  int ways = solve();
  printf("%s\n", ways == 0 ? "NONE" : ways == 1 ? "UNIQUE" : "MULTIPLE");
  if (ways == 1)
    for (int x = (0); x < (n); ++x) printf("%s\n", ans[x]);
}
int main() {
  run();
  return 0;
}
