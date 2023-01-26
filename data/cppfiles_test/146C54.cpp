#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, q, B, nxt[maxn], lst[maxn], np[maxn];
void update(int x) {
  int y = nxt[x];
  for (int i = 1; i <= B - 1; i++) x = lst[x];
  for (int i = 1; i <= B; i++) np[x] = y, x = nxt[x], y = nxt[y];
}
int jump(int u, int k) {
  while (k) {
    if (k >= B)
      u = np[u], k -= B;
    else
      u = nxt[u], k--;
  }
  return u;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    lst[nxt[i]] = i;
  }
  B = sqrt(n);
  for (int i = 1; i <= n; i++) {
    int u = i;
    for (int j = 1; j <= B; j++) u = nxt[u];
    np[i] = u;
  }
  while (q--) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      swap(lst[nxt[x]], lst[nxt[y]]);
      swap(nxt[x], nxt[y]);
      update(x), update(y);
    } else
      cout << jump(x, y) << '\n';
  }
  return 0;
}
