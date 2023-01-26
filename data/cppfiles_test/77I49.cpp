#include <bits/stdc++.h>
using namespace std;
char ch;
int bo;
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void rd(int &x) {
  x = bo = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline void RD(long long &x) {
  x = bo = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline long long RD() {
  long long x;
  RD(x);
  return x;
}
inline int rd() {
  int x;
  rd(x);
  return x;
}
inline void RD(char *s) {
  for (ch = getchar(); blank(ch); ch = getchar())
    ;
  for (; !blank(ch); ch = getchar()) *s++ = ch;
  *s = 0;
}
inline void RD(char &c) {
  for (ch = getchar(); blank(c); ch = getchar())
    ;
}
template <class T>
inline void OT(T x) {
  static char buf[20];
  char *p1 = buf;
  if (!x) *p1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *p1++ = x % 10 + '0', x /= 10;
  while (p1-- != buf) putchar(*p1);
}
const int maxn = 1e3 + 7;
int vis[maxn][maxn];
int wall[maxn][maxn][4];
int cnt;
int n, m;
int X[4] = {0, 1, 0, -1}, Y[4] = {-1, 0, 1, 0};
void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  cnt++;
  for (int i = 0; i < 4; i++)
    if (!wall[x][y][i]) {
      int nx = x + X[i], ny = y + Y[i];
      dfs(nx, ny);
    }
}
vector<int> ans;
int main() {
  n = rd(), m = rd();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int t = rd();
      for (int k = 0; k < 4; k++) wall[i][j][k] = t & (1 << k);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (int _i = 0; _i < ans.size(); _i++)
    OT(ans[_i]), putchar(" \n"[_i == ans.size() - 1]);
  ;
}
