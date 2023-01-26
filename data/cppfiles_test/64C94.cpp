#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int M = 2e5;
const long long mod = 998244353;
double eps = 1e-8;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long n, m, k;
int fa[N][2];
int getfa(int x, int ty) {
  if (x != fa[x][ty]) {
    fa[x][ty] = getfa(fa[x][ty], ty);
  }
  return fa[x][ty];
}
void merge(int x, int y, int ty) {
  int fx = getfa(x, ty), fy = getfa(y, ty);
  if (fx != fy) fa[fx][ty] = fy;
}
vector<int> vt[2];
vector<pair<int, int> > as;
void solvve() {
  n = read();
  int m1 = read(), m2 = read();
  for (int i(1); i <= n; ++i)
    for (int j(0); j <= 1; ++j) fa[i][j] = i;
  for (int i(1); i <= m1; ++i) {
    int x = read(), y = read();
    merge(x, y, 0);
  }
  for (int i(1); i <= m2; ++i) {
    int x = read(), y = read();
    merge(x, y, 1);
  }
  for (int i(2); i <= n; ++i) {
    int f0 = getfa(1, 0), f1 = getfa(1, 1), fi0 = getfa(i, 0),
        fi1 = getfa(i, 1);
    if (f0 != fi0 && f1 != fi1) {
      merge(i, 1, 0);
      merge(i, 1, 1);
      as.push_back({i, 1});
    }
  }
  for (int i(2); i <= n; ++i) {
    int f0 = getfa(1, 0), f1 = getfa(1, 1), fi0 = getfa(i, 0),
        fi1 = getfa(i, 1);
    if (f0 != fi0 && f1 != fi1)
      ;
    else if (f0 != fi0 && fa[i][0] == i) {
      vt[0].push_back(i);
    } else if (f1 != fi1 && fa[i][1] == i) {
      vt[1].push_back(i);
    }
  }
  for (int i = 0; i < min(vt[1].size(), vt[0].size()); i++) {
    as.push_back({vt[0][i], vt[1][i]});
  }
  printf("%d\n", as.size());
  for (auto it : as) {
    printf("%d %d\n", it.first, it.second);
  }
}
int main() {
  { solvve(); }
  return 0;
}
