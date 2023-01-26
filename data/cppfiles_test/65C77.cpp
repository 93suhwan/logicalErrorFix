#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int n, a[N], ans[N];
char s[N];
signed main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1), scanf("%s", s + 1);
  for (register int l = 1, r = n; l <= r;) {
    register int w = r - l + 1;
    if (s[w] == s[w - 1])
      ans[w] = l++;
    else
      ans[w] = r--;
  }
  for (register int i = 1; i <= n; ++i)
    printf("%d %c\n", a[ans[i]], "LR"[(ans[i] & 1) ^ (n & 1) ^ (s[n] == 'R')]);
  return 0;
}
