#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long q;
long long st[N], ed[N], last[N], ans[N], cnt;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> q;
  while (q--) {
    long long op;
    long long x;
    cin >> op >> x;
    if (op == 1) {
      if (!st[x]) {
        st[x] = ed[x] = ++cnt;
      } else {
        last[++cnt] = ed[x];
        ed[x] = cnt;
      }
    } else {
      long long y;
      cin >> y;
      if (x == y || !st[x]) continue;
      if (!st[y]) {
        st[y] = st[x];
        ed[y] = ed[x];
      } else {
        last[st[x]] = ed[y];
        ed[y] = ed[x];
      }
      st[x] = ed[x] = 0;
    }
  }
  for (long long i = (1); i <= (5e5); i++) {
    for (long long j = ed[i]; j; j = last[j]) ans[j] = i;
  }
  for (long long i = (1); i <= (cnt); i++) cout << ans[i] << " ";
}
