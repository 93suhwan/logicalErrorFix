#include <bits/stdc++.h>
using namespace std;
inline int gin() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = (s << 3) + (s << 1) + (c ^ 48);
    c = getchar();
  }
  return s * f;
}
const int N = 4e5 + 5;
int n, a[N], ans[N];
char s[N];
signed main() {
  n = gin();
  for (int i = 1; i <= n; i++) a[i] = gin();
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  for (int l = 1, r = n; l <= r;) {
    int x = r - l + 1;
    ans[x] = (s[x] == s[x - 1] ? l++ : r--);
  }
  for (int i = 1; i <= n; i++)
    printf("%d %c\n", a[ans[i]],
           (ans[i] & 1) ^ (n & 1) ^ (s[n] == 'R') ? 'R' : 'L');
  return 0;
}
