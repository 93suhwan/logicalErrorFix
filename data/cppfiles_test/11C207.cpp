#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct pp {
  int le, num, re;
};
pp a[N], b[N], c[N], d[N], e[N];
bool cmp(pp p, pp q) { return p.re > q.re; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      char arr[2 * N];
      scanf("%s", arr);
      int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, m;
      m = strlen(arr);
      for (int j = 0; arr[j]; j++) {
        if (arr[j] == 'a')
          a2++;
        else if (arr[j] == 'b')
          b2++;
        else if (arr[j] == 'c')
          c2++;
        else if (arr[j] == 'd')
          d2++;
        else if (arr[j] == 'e')
          e2++;
      }
      a[i].le = m, a[i].num = a2, a[i].re = 2 * a2 - m;
      ;
      b[i].le = m, b[i].num = b2, b[i].re = 2 * b2 - m;
      c[i].le = m, c[i].num = c2, c[i].re = 2 * c2 - m;
      d[i].le = m, d[i].num = d2, d[i].re = 2 * d2 - m;
      e[i].le = m, e[i].num = e2, e[i].re = 2 * e2 - m;
    }
    sort(a, a + n, cmp);
    sort(b, b + n, cmp);
    sort(c, c + n, cmp);
    sort(d, d + n, cmp);
    sort(e, e + n, cmp);
    int i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    int a3 = 0, a4 = 0, b3 = 0, b4 = 0, c3 = 0, c4 = 0, d3 = 0, d4 = 0, e3 = 0,
        e4 = 0;
    for (i = 0; i < n; i++) {
      a3 += a[i].re, a4 += a[i].le - a[i].num;
      b3 += b[i].re, b4 += b[i].le - b[i].num;
      c3 += c[i].re, c4 += c[i].le - c[i].num;
      d3 += d[i].re, d4 += d[i].le - d[i].num;
      e3 += e[i].re, e4 += e[i].le - e[i].num;
      if (a3 <= 0) flag1 = 1;
      if (b3 <= 0) flag2 = 1;
      if (c3 <= 0) flag3 = 1;
      if (d3 <= 0) flag4 = 1;
      if (e3 <= 0) flag5 = 1;
      if (flag1 && flag2 && flag3 && flag4 && flag5) break;
    }
    cout << i << '\n';
  }
  return 0;
}
