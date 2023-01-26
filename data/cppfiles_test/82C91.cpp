#include <bits/stdc++.h>
using namespace std;
int i, j, k, t, n, m, f[300500], q, l, r;
char c;
set<int> st[2005000];
int main() {
  ios::sync_with_stdio(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) {
      c = getchar();
      if (c == '+' || c == '-') {
        f[i] = f[i - 1] + ((c == '+') ? 1 : -1) * ((i & 1) ? 1 : -1);
      } else {
        i--;
      }
    }
    for (i = 1; i <= n; i++) {
      st[600005 + f[i] + f[i - 1]].insert(i);
    }
    while (q--) {
      scanf("%d%d", &l, &r);
      if ((r - l + 1) & 1) {
        puts("1");
        k = *st[600005 + f[r] + f[l - 1]].lower_bound(l);
        printf("%d\n", k);
      } else {
        if (f[r] == f[l - 1]) {
          puts("0");
        } else {
          puts("2");
          printf("%d ", r);
          r--;
          k = *st[600005 + f[r] + f[l - 1]].lower_bound(l);
          printf("%d\n", k);
        }
      }
    }
    for (i = 1; i <= n; i++) {
      if (!st[600005 + f[i] + f[i - 1]].empty()) {
        st[600005 + f[i] + f[i - 1]].clear();
      }
    }
  }
}
