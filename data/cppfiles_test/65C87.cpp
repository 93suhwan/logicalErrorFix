#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn];
char s[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] != s[i - 1]) {
      cnt++;
    }
  }
  int l = n - cnt, r = n - cnt;
  int flag1 = 0, flag2 = 0;
  printf("%d %c\n", a[n - cnt], s[1]);
  if (s[1] == 'L')
    flag1 = flag2 = 1;
  else
    flag1 = flag2 = 2;
  for (int i = 2; i <= n; i++) {
    if (s[i] == s[i - 1]) {
      l--;
      if (flag1 == 1) {
        printf("%d R\n", a[l]);
        flag1 = 2;
      } else {
        printf("%d L\n", a[l]);
        flag1 = 1;
      }
    } else {
      r++;
      if (flag2 == 1) {
        printf("%d R\n", a[r]);
        flag2 = 2;
      } else {
        flag2 = 1;
        printf("%d L\n", a[r]);
      }
    }
  }
  return 0;
}
