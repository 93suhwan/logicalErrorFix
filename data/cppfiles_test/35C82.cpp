#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], prim[maxn], tot, flag[maxn], mi[maxn], l[maxn];
vector<int> st[maxn];
void init(int n) {
  mi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!flag[i]) prim[tot++] = i, mi[i] = i;
    for (int j = 0; j < tot && prim[j] * i <= n; ++j) {
      flag[i * prim[j]] = 1;
      if (i % prim[j] == 0) {
        mi[i * prim[j]] = mi[i];
        break;
      }
      mi[i * prim[j]] = prim[j];
    }
  }
}
char s[maxn];
int main() {
  init(maxn - 1);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '*') {
      l[i] = i;
      int u = a[i];
      while (u != 1) {
        st[mi[u]].push_back(i);
        u /= mi[u];
      }
    } else {
      l[i] = i;
      int u = a[i];
      while (u != 1) {
        if (st[mi[u]].empty()) {
          l[i] = 0;
        } else {
          l[i] = min(l[i], st[mi[u]].back());
          st[mi[u]].pop_back();
        }
        u /= mi[u];
      }
    }
  }
  vector<pair<int, int>> st2;
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    int cnt = 1;
    while (!st2.empty() && st2.back().first >= i) {
      cnt += st2.back().second;
      st2.pop_back();
    }
    st2.push_back({l[i], cnt});
    if (l[i] == i) ans += cnt;
  }
  printf("%lld\n", ans);
}
