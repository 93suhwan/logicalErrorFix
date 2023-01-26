#include <bits/stdc++.h>
using namespace std;
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
inline int Read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string s;
int f[100][2];
int main() {
  int T;
  T = Read();
  while (T--) {
    bool flag = false;
    int n;
    cin >> n >> s;
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n - 1; ++i) {
      f[i][0] = f[i - 1][0];
      f[i][1] = f[i - 1][1];
      if (s[i] == 'a') f[i][0]++;
      if (s[i] == 'b') f[i][1]++;
    }
    for (int l = 0; l <= n - 1; ++l) {
      for (int r = l + 1; r <= n - 1; ++r) {
        int a = f[r][0] - f[l - 1][0];
        int b = f[r][1] - f[l - 1][1];
        if (a == b) {
          cout << l + 1 << ' ' << r + 1 << '\n';
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) cout << -1 << ' ' << -1 << '\n';
  }
  return 0;
}
