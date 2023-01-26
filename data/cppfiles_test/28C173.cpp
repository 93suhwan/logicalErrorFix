#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int fa[N], c[N], d[N], a[N], n, m, pos[N], cnt[N], ans[N], T;
int getf(int x) { return fa[x] == x ? x : fa[x] = getf(fa[x]); }
int pd(int k) {
  for (int i = 1; i <= n; i++) {
    c[i] = (i + k) % n;
    if (c[i] == 0) c[i] = n;
    fa[i] = i;
  }
  int cnt = n;
  for (int i = 1; i <= n; i++) {
    int f1 = getf(pos[i]), f2 = getf(c[i]);
    if (f1 != f2) {
      cnt--;
      fa[f1] = f2;
    }
  }
  if (cnt >= n - m) return 1;
  return 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    int h = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] > i)
        d[i] = i + n - a[i];
      else
        d[i] = i - a[i];
      cnt[d[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (cnt[i] < n / 3) continue;
      if (pd(i)) ans[++h] = i;
    }
    printf("%d ", h);
    for (int i = 1; i <= h; i++) printf("%d ", ans[i]);
    cout << endl;
  }
  return 0;
}
