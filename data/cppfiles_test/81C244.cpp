#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long mod = 1e9 + 7;
int t, n, a[N], res[N];
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '+') {
        if (i & 1)
          res[i] = res[i - 1] + 1;
        else
          res[i] = res[i - 1] - 1;
      } else {
        if (i & 1)
          res[i] = res[i - 1] - 1;
        else
          res[i] = res[i - 1] + 1;
      }
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (res[r] - res[l - 1] == 0) {
        puts("0");
      } else {
        int k = res[r] - res[l - 1];
        if ((abs(k)) & 1) {
          puts("1");
        } else
          puts("2");
      }
    }
  }
  return 0;
}
