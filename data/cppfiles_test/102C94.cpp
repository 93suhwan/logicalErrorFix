#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, sgn = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return sgn * x;
}
const int maxn = 1000000 + 5;
int T;
int n, m;
int l[maxn], r[maxn], u[maxn], d[maxn];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    cin >> s;
    int len = s.length();
    l[0] = r[0] = u[0] = d[0] = 0;
    int x = 0, y = 0;
    int ansx = 1, ansy = 1;
    for (int t = 1; t <= len; ++t) {
      int dx = 0, dy = 0;
      if (s[t - 1] == 'L')
        dx = -1;
      else if (s[t - 1] == 'R')
        dx = 1;
      else if (s[t - 1] == 'U')
        dy = 1;
      else
        dy = -1;
      x += dx;
      y += dy;
      l[t] = max(l[t - 1], -x);
      r[t] = max(r[t - 1], x);
      u[t] = max(u[t - 1], y);
      d[t] = max(d[t - 1], -y);
      if (l[t] + r[t] > m - 1) break;
      if (u[t] + d[t] > n - 1) break;
      ansx = l[t] + 1;
      ansy = u[t] + 1;
    }
    cout << ansy << ' ' << ansx << endl;
  }
  return 0;
}
