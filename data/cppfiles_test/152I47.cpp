#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e3 + 7;
int T, n, a[N];
pair<int, int> c[N];
void add(int x, pair<int, int> v) {
  while (x <= n * 2 + 5) {
    c[x] = max(c[x], v);
    x += x & -x;
  }
}
pair<int, int> qry(int x) {
  pair<int, int> ret = {0, 0};
  while (x) {
    ret = max(ret, c[x]);
    x -= x & -x;
  }
  return ret;
}
int vis[N], last[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i <= n * 2 + 10; i++) c[i] = {0, 0};
    scanf("%d", &n);
    int ans = 0;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      scanf("%d", &a[i]);
      pair<int, int> f0 = qry(a[i] - 1 + n + 1);
      f0.first++;
      pair<int, int> f1 = qry(-a[i] - 1 + n + 1);
      f1.first++;
      last[i * 2 - 1] = f0.second;
      last[i * 2] = f1.second;
      f0.second = i * 2 - 1;
      f1.second = i * 2;
      add(a[i] + n + 1, f0);
      add(-a[i] + n + 1, f1);
      if (f0.first > ans) ans = f0.first, pos = f0.second;
      if (f1.first > ans) ans = f1.first, pos = f1.second;
    }
    for (int i = pos; i; i = last[i]) vis[(i + 1) / 2] = i % 2 ? 1 : -1;
    int lst = -n + 1;
    int ok = 1;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        if (-a[i] > lst) a[i] = -a[i];
        if (a[i] < lst) ok = 0;
        lst = a[i];
      }
    for (int i = 1; i <= n; i++)
      if (vis[i]) a[i] *= vis[i];
    puts(ok ? "YES" : "NO");
    if (ok) {
      for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    }
  }
}
