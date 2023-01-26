#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, lim = 500;
int n, m, x[maxn], y[maxn], now[maxn], ri[maxn], u[maxn], ans[maxn], val[lim],
    ty[maxn], le[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &ty[i], &u[i]);
    if (ty[i] == 1)
      now[u[i]] = i;
    else
      ri[now[u[i]]] = i - 1, le[i] = now[u[i]], now[u[i]] = 0;
  }
  for (int i = 1; i <= n; ++i)
    if (now[i]) ri[now[i]] = m;
  for (int i = 1; i <= m; ++i) {
    if (u[i]) {
      if (x[u[i]] + y[u[i]] >= lim) {
        for (int j = i + x[u[i]]; j <= ri[i]; j += x[u[i]] + y[u[i]])
          ++ans[j], --ans[j + y[u[i]]];
      }
    }
  }
  for (int i = 1; i <= m; ++i) ans[i] += ans[i - 1];
  for (int i = 2; i < lim; ++i) {
    for (int j = 0; j < i; ++j) val[j] = 0;
    for (int t = 1; t <= m; ++t) {
      if (x[u[t]] + y[u[t]] == i) {
        if (ty[t] == 1) {
          for (int j = x[u[t]]; j < x[u[t]] + y[u[t]]; ++j) ++val[(t + j) % i];
        } else {
          for (int j = x[u[t]]; j < x[u[t]] + y[u[t]]; ++j)
            --val[(le[t] + j) % i];
        }
      }
      ans[t] += val[t % i];
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}
