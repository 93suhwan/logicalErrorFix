#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
const int N = 2e5 + 10;
int n;
int a[N], ans[N];
char opt[N];
signed main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  scanf("%s", opt + 1);
  int l = 1, r = n;
  while (l <= r) {
    int tmp = r - l + 1;
    ans[tmp] = (opt[tmp] == opt[tmp - 1] ? l++ : r--);
  }
  for (register int i = 1; i <= n; ++i) {
    printf("%d ", a[ans[i]]);
    if ((ans[i] & 1) ^ (n & 1) ^ (opt[n] == 'L'))
      printf("L\n");
    else
      printf("R\n");
  }
  return 0;
}
