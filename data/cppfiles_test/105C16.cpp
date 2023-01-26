#include <bits/stdc++.h>
using namespace std;
int t, n;
struct node {
  int a, b, m, x, i, ans1, ans2;
} x[200010];
int a[200010], b[200010];
bool cmp(node a, node b) { return a.x < b.x; }
bool cmp3(node a, node b) { return a.i < b.i; }
struct node2 {
  int l, r, i;
} y[200010];
bool cmp2(node2 a, node2 b) { return a.l > b.l; }
int anss[200010];
int ch(int l, int r) {
  int ans = 0;
  for (int i = l, j = 1; i <= r; i++, j++) {
    y[j].l = x[i].a - min(x[i].m, x[i].a);
    y[j].r = x[i].a - max(0, x[i].m - x[i].b);
    y[j].i = x[i].i;
  }
  sort(y + 1, y + r - l + 2, cmp2);
  int add = 0, now = 2e9;
  for (int i = 1, j = l; j <= r; j++, i++) {
    if (y[i].r < now) {
      ans++;
      now = y[i].l;
      anss[y[i].i] = now;
    } else {
      anss[y[i].i] = now;
    }
  }
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> x[i].a >> x[i].b >> x[i].m, x[i].x = x[i].a + x[i].b - x[i].m,
                                         x[i].i = i;
    sort(x + 1, x + 1 + n, cmp);
    int ans = 0;
    int j = 1;
    for (int i = 1; i <= n; i++) {
      if (x[i].x != x[j].x) {
        ans += ch(j, i - 1);
        j = i;
      }
    }
    ans += ch(j, n);
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
      x[i].ans1 = x[i].a - anss[x[i].i];
      x[i].ans2 = (x[i].m - x[i].a + anss[x[i].i]);
    }
    sort(x + 1, x + 1 + n, cmp3);
    for (int i = 1; i <= n; i++) cout << x[i].ans1 << ' ' << x[i].ans2 << endl;
  }
}
