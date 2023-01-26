#include <bits/stdc++.h>
using namespace std;
const int dx[5] = {1, 1, 0, -1, -1}, dy[5] = {0, 1, 1, 0, 1};
const int N = 1e2 + 10;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w *= -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int T, n;
char s[N], t[N];
int main() {
  T = read();
  while (T--) {
    n = read();
    cin >> s + 1;
    cin >> t + 1;
    if (s[1] != '0') {
      puts("NO");
      continue;
    }
    bool flag = true;
    for (register int i = 2; i <= n; i++) {
      if (s[i] == '1' && t[i] == '1') {
        puts("NO");
        flag = false;
        break;
      }
    }
    if (flag) puts("YES");
  }
  return 0;
}
