#include <bits/stdc++.h>
using namespace std;
long long row[200010], col[200010], ans, n;
int x[200010], y[200010], visx[200010], visy[200010];
int main() {
  int T, i;
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &x[i], &y[i]);
      row[x[i]]++;
      col[y[i]]++;
    }
    ans = 1ll * n * (n - 1) * (n - 2) / 6;
    long long s1;
    s1 = 0;
    for (i = 1; i <= n; i++) {
      s1 += 1ll * (row[x[i]] - 1) * (col[y[i]] - 1);
    }
    cout << ans - s1 << endl;
    for (i = 1; i <= n; i++) {
      row[x[i]] = col[y[i]] = visx[x[i]] = visy[y[i]] = 0;
    }
  }
}
