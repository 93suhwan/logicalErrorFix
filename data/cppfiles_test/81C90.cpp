#include <bits/stdc++.h>
using namespace std;
int t, n, q, sum[1000005];
char c;
int main() {
  scanf("%d", &t);
  for (int i1 = 1; i1 <= t; i1++) {
    scanf("%d%d", &n, &q);
    scanf("%c", &c);
    for (int i = 1; i <= n; i++) {
      scanf("%c", &c);
      if (c == '+') sum[i] = sum[i - 1] + (pow(-1, (i - 1) % 2));
      if (c == '-') sum[i] = sum[i - 1] - (pow(-1, (i - 1) % 2));
    }
    for (int i = 1; i <= q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (l > r) swap(l, r);
      if ((r - l + 1) % 2 == 1)
        printf("1\n");
      else if (sum[r] - sum[l - 1] == 0)
        printf("0\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
