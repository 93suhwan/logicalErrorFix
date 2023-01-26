#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int N = 1000005;
int n, a[N], i, j;
char c[N];
char x(char c, int f) {
  if (f == 1)
    return c == 'L' ? 'R' : 'L';
  else
    return c;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  scanf("%s", c + 1);
  for (i = 1; i <= n;) {
    for (j = i; c[i] == c[j]; ++j)
      ;
    for (int k = j - 1; k >= i; --k)
      printf("%d %c\n", a[k], x(c[i], j - 1 - k & 1));
    i = j;
  }
}
