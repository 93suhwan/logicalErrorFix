#include <bits/stdc++.h>
using namespace std;
int n, minn, maxn;
int p[100010], lst[100010], nxt[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("? ");
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      if (i == j)
        printf("2 "), fflush(stdout);
      else
        printf("1 "), fflush(stdout);
    }
    int x;
    scanf("%d", &x);
    if (x == i)
      continue;
    else if (!x)
      maxn = i;
    else
      nxt[i] = x, lst[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    printf("? "), fflush(stdout);
    for (int j = 1; j <= n; j++) {
      if (i == j)
        printf("1 "), fflush(stdout);
      else
        printf("2 "), fflush(stdout);
    }
    int x;
    scanf("%d", &x);
    if (x == i)
      continue;
    else if (!x)
      minn = i;
    else
      lst[i] = x, nxt[x] = i;
  }
  if (maxn) p[n] = maxn;
  if (minn) p[1] = minn;
  int now = lst[maxn], x = n - 1;
  while (now) {
    p[x] = now;
    now = lst[now];
    x--;
  }
  now = nxt[minn], x = 2;
  while (now) {
    p[x] = now;
    now = nxt[now];
    x++;
  }
  printf("! ");
  fflush(stdout);
  for (int i = 1; i <= n; i++) printf("%d ", p[i]), fflush(stdout);
  return 0;
}
