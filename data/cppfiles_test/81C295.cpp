#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
char str[N];
int sum[N];
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, op;
    scanf("%d%d", &n, &op);
    scanf("%s", str + 1);
    int x = 0, k = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        if (str[i] == '+')
          sum[i] = sum[i - 1] - 1;
        else
          sum[i] = sum[i - 1] + 1;
      } else {
        if (str[i] == '+')
          sum[i] = sum[i - 1] + 1;
        else
          sum[i] = sum[i - 1] - 1;
      }
    }
    while (op--) {
      int l, r;
      scanf("%d%d", &l, &r);
      if ((r - l + 1) % 2 == 0) {
        if ((sum[r] - sum[l - 1]) == 0)
          printf("%d\n", 0);
        else
          printf("%d\n", 2);
      } else {
        printf("%d\n", 1);
      }
    }
  }
}
