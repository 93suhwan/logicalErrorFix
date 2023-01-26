#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char ch) {
  print(x), putchar(ch);
}
template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
const int N = 1005;
char s[N], t[N];
int n, m;
int f[N], g[N];
void solve() {
  scanf("%s%s", s + 1, t + 1);
  memset(f, 0, 4 * (n + 1));
  n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == t[1]) f[i] = 1;
  }
  for (int i = 2; i <= m; i++) {
    memcpy(g, f, 4 * (n + 1));
    memset(f, 0, 4 * (n + 1));
    for (int j = 1; j <= n; j++) {
      if (g[j]) {
        if (j > 1 && s[j - 1] == t[i]) f[j - 1] = 1;
        if (j < n && s[j + 1] == t[i]) f[j + 1] = 1;
      }
    }
  }
  bool ok = 0;
  for (int i = 1; i <= n; i++) ok |= f[i];
  puts(ok ? "YES" : "NO");
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}
