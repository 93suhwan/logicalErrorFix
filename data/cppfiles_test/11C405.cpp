#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
char s[N];
int a[N], b[N], c[N], d[N], e[N];
int main() {
  int t, n, m, x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      m = strlen(s);
      int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'a')
          a1++;
        else if (s[j] == 'b')
          b1++;
        else if (s[j] == 'c')
          c1++;
        else if (s[j] == 'd')
          d1++;
        else if (s[j] == 'e')
          e1++;
      }
      a[i] = 2 * a1 - m, b[i] = 2 * b1 - m, c[i] = 2 * c1 - m,
      d[i] = 2 * d1 - m, e[i] = 2 * e1 - m;
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    sort(d + 1, d + 1 + n);
    sort(e + 1, e + 1 + n);
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int i = n; i >= 1; i--) {
      if (sum1 + a[i] > 0) sum1 += a[i], ans1++;
      if (sum2 + b[i] > 0) sum2 += b[i], ans2++;
      if (sum3 + c[i] > 0) sum3 += c[i], ans3++;
      if (sum4 + d[i] > 0) sum4 += d[i], ans4++;
      if (sum5 + e[i] > 0) sum5 += e[i], ans5++;
    }
    printf("%d\n", max(ans1, max(ans2, max(ans3, max(ans4, ans5)))));
  }
  return 0;
}
