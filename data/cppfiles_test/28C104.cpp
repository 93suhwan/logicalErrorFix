#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[300010], t[300010], p[300010], v[300010], rk[300010];
vector<int> ans;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    ans.clear();
    for (int i = 0; i < n; i++) v[i] = t[i] = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), rk[--a[i]] = i;
    for (int i = 0; i < n; i++) t[(rk[i] - i + n) % n]++;
    for (int k = 0; k < n; k++) {
      if (t[k] + (n - t[k]) / 2 < n - m) continue;
      for (int i = 0; i < n; i++) v[i] = 0;
      int s = 0;
      for (int i = 0; i < n; i++)
        if (!v[i]) {
          s++;
          int now = i;
          while (!v[now]) v[now] = 1, now = rk[(now - k + n) % n];
        }
      if (s >= n - m) ans.push_back(k);
    }
    int sz = ans.size();
    printf("%d ", sz);
    for (int i = 0; i < sz; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
