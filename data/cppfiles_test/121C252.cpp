#include <bits/stdc++.h>
using namespace std;
int a[100009], b[100009], cnt[2][2];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    int d1 = -1, d2 = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%1d", &b[i]);
    for (int i = 1; i <= n; i++) cnt[a[i]][b[i]]++;
    if (cnt[1][1] == cnt[0][0] + 1) d1 = cnt[1][1] + cnt[0][0];
    if (cnt[1][0] == cnt[0][1]) d2 = cnt[1][0] + cnt[0][1];
    if (cnt[1][1] + cnt[0][0] == n)
      puts("0");
    else if (d1 == -1 && d2 == -1)
      puts("-1");
    else if (d1 == -1)
      printf("%d\n", d2);
    else if (d2 == -1)
      printf("%d\n", d1);
    else
      printf("%d\n", min(d1, d2));
    memset(cnt, 0, sizeof(cnt));
  }
  return 0;
}
