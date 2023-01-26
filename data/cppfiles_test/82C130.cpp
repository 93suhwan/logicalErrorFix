#include <bits/stdc++.h>
using namespace std;
int i, n, m, l, r, t, w, x, T, mid, a[300300];
map<int, set<int> > f;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d\n", &n, &m);
    f.erase(f.begin(), f.end());
    for (i = 1; i <= n; i++)
      a[i] = a[i - 1] + ((i & 1) ? 1 : -1) * ((getchar() == '+') ? 1 : -1),
      f[a[i] + a[i - 1]].insert(i);
    for (i = 1; i <= m; i++) {
      scanf("%d %d", &l, &r);
      if (!(a[l - 1] ^ a[r])) {
        printf("0\n");
        continue;
      }
      if ((r - l) & 1)
        printf("2\n%d ", r--);
      else
        printf("1\n");
      printf("%d\n", *f[a[l - 1] + a[r]].lower_bound(l));
    }
  }
  return 0;
}
