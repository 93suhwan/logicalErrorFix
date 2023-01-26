#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
set<int> st[maxn];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    st[u].insert(v);
    st[v].insert(u);
  }
  int single = 0;
  for (int i = 1; i <= n; i++) {
    if (st[i].size() == 0)
      single++;
    else if (*st[i].rbegin() < i)
      single++;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int typ, u, v;
    scanf("%d", &typ);
    if (typ == 1) {
      scanf("%d %d", &u, &v);
      if (u > v) swap(u, v);
      if (st[u].size() == 0)
        single--;
      else if (*st[u].rbegin() < u)
        single--;
      st[u].insert(v);
      st[v].insert(u);
    } else if (typ == 2) {
      scanf("%d %d", &u, &v);
      if (u > v) swap(u, v);
      st[u].erase(st[u].find(v));
      st[v].erase(st[v].find(u));
      if (st[u].size() == 0)
        single++;
      else if (*st[u].rbegin() < u)
        single++;
    } else {
      printf("%d\n", single);
    }
  }
  return 0;
}
