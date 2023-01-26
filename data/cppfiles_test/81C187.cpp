#include <bits/stdc++.h>
using namespace std;
const int MAXN = 314514;
int a[MAXN], sum[MAXN];
char ch[MAXN];
int m, n, t, q;
int main() {
  cin >> t;
  for (int z = 1; z <= t; z++) {
    memset(ch, 0, sizeof(ch));
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    scanf("%d%d", &n, &q);
    cin >> ch;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        if (ch[i - 1] == '+')
          a[i] = 1;
        else
          a[i] = -1;
      } else {
        if (ch[i - 1] == '+')
          a[i] = -1;
        else
          a[i] = 1;
      }
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (sum[r] - sum[l - 1] == 0) {
        printf("0\n");
        continue;
      } else if ((r - l + 1) % 2 == 1) {
        printf("1\n");
        continue;
      } else {
        printf("2\n");
        continue;
      }
    }
  }
  return 0;
}
