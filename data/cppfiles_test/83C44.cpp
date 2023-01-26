#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, f = 1;
  char ch = getchar();
  while (ch < '0' or ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') w = w * 10 + ch - '0', ch = getchar();
  return w * f;
}
const int maxn = 5005;
int lcp[maxn][maxn], T, f[maxn], N;
char str[maxn];
int main() {
  T = read();
  while (T--) {
    N = read();
    scanf("%s", str + 1);
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++) lcp[i][j] = 0;
    for (int i = N; i >= 1; i--) {
      f[i] = 0;
      for (int j = N; j >= 1; j--)
        if (str[i] == str[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (f[j] - lcp[i][j] > f[i] and str[j + lcp[i][j]] < str[i + lcp[i][j]])
          f[i] = f[j] - lcp[i][j];
      }
      f[i] += N - i + 1;
      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
