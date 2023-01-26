#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  char c = getchar();
  long long x = 0, w = 1;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x * w;
}
inline void cmx(int& a, int b) { a = a > b ? a : b; }
inline void cmn(int& a, int b) { a = a < b ? a : b; }
const int N = 100005;
int n, a[N], b[N];
char s[N];
int main() {
  int T = rd();
  while (T--) {
    n = rd();
    scanf("%s", s + 1);
    for (register int i = (1); i <= (n); ++i) a[i] = s[i] - '0';
    scanf("%s", s + 1);
    for (register int i = (1); i <= (n); ++i) b[i] = s[i] - '0';
    int ff = 0;
    for (register int i = (1); i <= (n); ++i)
      if (a[i] != b[i]) ff = 1;
    if (!ff) {
      puts("0");
      continue;
    }
    ff = 0;
    for (register int i = (1); i <= (n); ++i)
      if (a[i]) ff = 1;
    if (!ff) {
      puts("-1");
      continue;
    }
    ff = 0;
    for (register int i = (1); i <= (n); ++i)
      if (b[i]) ff = 1;
    if (!ff) {
      puts("-1");
      continue;
    }
    int ans = n + 1;
    int s1 = 0;
    for (register int i = (1); i <= (n); ++i)
      if (a[i] != b[i]) s1++;
    if (~s1 & 1) ans = min(ans, s1);
    if ((n - s1) & 1) ans = min(ans, n - s1);
    if (ans == n + 1)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
