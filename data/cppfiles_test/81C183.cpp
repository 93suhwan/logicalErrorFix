#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
int n, q, t;
char s[maxn];
int a[maxn], b[maxn];
int main() {
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d%d", &n, &q);
    scanf(" %s", s);
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (s[i] == '+')
          a[i + 1] = 1;
        else
          a[i + 1] = -1;
      } else {
        if (s[i] == '+')
          b[i + 1] = 1;
        else
          b[i + 1] = -1;
      }
    }
    a[2] = a[1];
    for (int i = 3; i <= n; i++) {
      if (i % 2)
        a[i] += a[i - 2], b[i] = b[i - 1];
      else
        b[i] += b[i - 2], a[i] = a[i - 1];
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      int tt1 = a[r] - a[l - 1];
      int tt2 = b[r] - b[l - 1];
      if (tt1 == tt2) {
        printf("0\n");
      } else if ((abs(tt1 - tt2)) % 2 == 1) {
        printf("1\n");
      } else
        printf("2\n");
    }
  }
  return 0;
}
