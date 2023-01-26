#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN];
char s[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1]) m++;
  int t = (n - m & 1) ^ (s[1] == 'L');
  printf("%d %c\n", a[n - m], s[1]);
  int l = n - m, r = n - m;
  for (int i = 2; i <= n; i++) {
    if (s[i] == s[i - 1])
      l--, printf("%d %c\n", a[l], (l & 1) == t ? 'R' : 'L');
    else
      r++, printf("%d %c\n", a[r], (r & 1) == t ? 'R' : 'L');
  }
  return 0;
}
