#include <bits/stdc++.h>
using namespace std;
const int N = 50010, M = 50000;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
int n;
int a[N][7], c[N];
struct P {
  int x, y, z, id;
} p[N];
bool cmp(P a, P b) { return a.x < b.x; }
int s[N];
void modify(int x, int v) {
  for (; x <= M; x += (x & (-x))) s[x] = min(s[x], v);
}
int query(int x) {
  int t = inf;
  for (; x; x -= (x & (-x))) t = min(t, s[x]);
  return t;
}
void solve(int A, int B, int C) {
  for (int i = 1; i <= n; i++)
    p[i].x = a[i][A], p[i].y = a[i][B], p[i].z = a[i][C], p[i].id = i;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    if (query(p[i].y - 1) < p[i].z) c[p[i].id] = 1;
    modify(p[i].y, p[i].z);
  }
  for (int i = 1; i <= n; i++) {
    int x = p[i].y;
    for (; x <= M; x += (x & (-x))) s[x] = inf;
  }
}
int main() {
  for (int i = 1; i <= M; i++) s[i] = inf;
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 5; j++) a[i][j] = read();
    solve(1, 2, 3);
    solve(1, 2, 4);
    solve(1, 2, 5);
    solve(1, 3, 4);
    solve(1, 3, 5);
    solve(1, 4, 5);
    solve(2, 3, 4);
    solve(2, 3, 5);
    solve(2, 4, 5);
    solve(3, 4, 5);
    int ans = -1;
    for (int i = 1; i <= n; i++)
      if (!c[i]) ans = i;
    cout << ans << endl;
  }
}
