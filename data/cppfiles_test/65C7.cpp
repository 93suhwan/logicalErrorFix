#include <bits/stdc++.h>
using namespace std;
int n, a[200001], i, l, r, cnt;
char s[200001], q[3] = "LR";
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  for (i = 1; i <= n; i++) cnt += s[i] != s[i - 1];
  cnt = n - cnt + 1;
  l = cnt - 1;
  r = cnt + 1;
  printf("%d %c\n", a[cnt], s[1]);
  if (s[1] == 'R') swap(q[0], q[1]);
  for (i = 2; i <= n; i++)
    if (s[i] != s[i - 1])
      printf("%d %c\n", a[r], q[r - cnt & 1]), r++;
    else
      printf("%d %c\n", a[l], q[cnt - l & 1]), l--;
}
