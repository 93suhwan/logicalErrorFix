#include <bits/stdc++.h>
using namespace std;
int t;
int n, q;
int l, r;
char ch[300005];
int a[300005];
int sum1[300005], sum2[300005];
bool check(int l, int r) {
  if (l & 1) {
    if (sum1[r] - sum1[l - 1] == 0) return true;
    return false;
  } else {
    if (sum2[r] - sum2[l - 1] == 0) return true;
    return false;
  }
}
int main() {
  scanf(" %d", &t);
  while (t--) {
    scanf(" %d %d", &n, &q);
    scanf(" %s", ch + 1);
    for (int i = 1; i <= n; i++) {
      if (ch[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        sum1[i] = sum1[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + a[i] * -1;
      } else {
        sum1[i] = sum1[i - 1] + a[i] * -1;
        sum2[i] = sum2[i - 1] + a[i];
      }
    }
    for (int i = 1; i <= q; i++) {
      scanf(" %d %d", &l, &r);
      int len = r - l + 1;
      if (!(len & 1)) {
        if (check(l, r))
          printf("0\n");
        else
          printf("2\n");
      } else
        printf("1\n");
    }
  }
  return 0;
}
