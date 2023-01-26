#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 4;
int ans[maxn], val[maxn], f[maxn], mp[maxn];
void init() {
  for (int i = 0; i < maxn; i++) f[i] = i;
}
int getv(int x) {
  if (f[x] == x) {
    ans[x] = val[x];
    return x;
  } else {
    f[x] = getv(f[x]);
    ans[x] = val[f[x]];
    return f[x];
  }
}
void solv() {
  init();
  int q, op, x, y, cnt = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      if (!mp[x]) mp[x] = cnt + 1;
      f[++cnt] = mp[x];
      val[mp[x]] = x;
    } else {
      scanf("%d %d", &x, &y);
      if (x == y) continue;
      if (!mp[y]) {
        val[f[mp[x]]] = y;
        mp[y] = mp[x];
        mp[x] = 0;
        continue;
      }
      f[mp[x]] = mp[y];
      mp[x] = 0;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    ans[i] = val[getv(i)];
  }
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
  }
}
signed main() { solv(); }
