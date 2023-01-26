#include <bits/stdc++.h>
using namespace std;
int n, q, cnt, a[150005], f[1000005], pri[150005], vis[1000005];
set<int> g[1000005];
void init(int lim) {
  for (int i = 1; i <= lim + 1; ++i) f[i] = i;
  for (int i = 2; i <= lim; ++i) {
    if (!vis[i]) pri[++cnt] = i;
    for (int j = 1; j <= cnt && pri[j] * i <= lim; ++j) {
      vis[pri[j] * i] = 1;
      if (i % pri[j] == 0) continue;
    }
  }
}
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
int main() {
  scanf("%d%d", &n, &q);
  init(1e6 + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    int tmp = a[i];
    for (int j = 1; pri[j] * pri[j] <= tmp; ++j)
      if (tmp % pri[j] == 0) {
        int fx = find(a[i]), fy = find(pri[j]);
        if (fx != fy) f[fx] = fy;
        while (tmp % pri[j] == 0) tmp /= pri[j];
      }
    if (tmp > 1) {
      int fx = find(a[i]), fy = find(tmp);
      if (fx != fy) f[fx] = fy;
    }
  }
  for (int i = 1; i <= n; ++i) {
    set<int> st;
    int tmp = a[i] + 1;
    st.insert(find(a[i]));
    for (int j = 1; pri[j] * pri[j] <= tmp; ++j)
      if (tmp % pri[j] == 0) {
        st.insert(find(pri[j]));
        while (tmp % pri[j] == 0) tmp /= pri[j];
      }
    if (tmp > 1) st.insert(find(tmp));
    for (auto e1 : st)
      for (auto e2 : st)
        if (e1 != e2) {
          g[e1].insert(e2);
          g[e2].insert(e1);
        }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = find(a[x]), fy = find(a[y]);
    if (fx == fy)
      printf("0\n");
    else if (g[fx].count(fy))
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
