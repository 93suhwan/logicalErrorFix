#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, x[N], y[N], a[N], p[N], buc[555][555];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= m; i++) {
    int op, k, c, ans = 0;
    scanf("%d%d", &op, &k), c = x[k] + y[k];
    if (op == 1) {
      a[k] = i;
      if (c < 555)
        for (int j = 0; j < c; j++) buc[c][(i + j) % c] += j >= x[k];
      else
        for (int j = i + x[k]; j <= m; j += c)
          p[j]++, p[min(m + 1, j + y[k])]--;
    } else {
      if (c < 555)
        for (int j = 0; j < c; j++) buc[c][(a[k] + j) % c] -= j >= x[k];
      else
        for (int j = a[k] + x[k]; j <= m; j += c)
          p[max(i, j)]--, p[max(i, min(m + 1, j + y[k]))]++;
    }
    for (int j = 2; j < 555; j++) ans += buc[j][i % j];
    printf("%d\n", ans + (p[i] += p[i - 1]));
  }
  return 0;
}
