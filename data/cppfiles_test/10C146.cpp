#include <bits/stdc++.h>
using namespace std;
struct node {
  int s, id, c;
} a[200010];
int T, n, k, tmp = 0, h[200010], idx[200010], mx, mn, f = 0;
bool cmp1(node a, node b) { return a.s < b.s; }
bool cmp2(node a, node b) { return a.id < b.id; }
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    tmp = 0;
    memset(h, 0, sizeof(h));
    f = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].s;
      a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++) {
      if (tmp == k) tmp = 0;
      if (a[i].s == a[i - 1].s)
        f++;
      else
        f = 1;
      if (f > k) continue;
      a[i].c = ++tmp;
      h[tmp]++;
      idx[tmp] = a[i].id;
    }
    sort(a + 1, a + n + 1, cmp2);
    mx = mn = h[1];
    for (int i = 1; i <= n; i++)
      if (h[i]) {
        mx = max(mx, h[i]);
        mn = min(mn, h[i]);
      }
    if (mx > mn) {
      for (int i = 1; i <= n; i++) {
        if (h[i] == mx) a[idx[i]].c = 0;
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i].c << " ";
    puts("");
  }
  return 0;
}
