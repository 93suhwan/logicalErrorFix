#include <bits/stdc++.h>
using namespace std;
long long t, n, m, rb, cb, rd, cd, l, r;
struct node {
  long long id, len, l, r;
} a[10005];
bool f[10005];
bool cmp(node x, node y) { return x.len < y.len; }
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i].l >> a[i].r;
      a[i].id = i;
      a[i].len = a[i].r - a[i].l;
      f[i] = 0;
      sum += i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (long long i = 1; i <= n; i++) {
      if (a[i].l == a[i].r) {
        f[a[i].l] = 1;
        cout << a[i].l << " " << a[i].r << " " << a[i].l << endl;
        sum -= a[i].l;
        continue;
      }
      long long l = a[i].l, r = a[i].r;
      if (f[l] == 1 && f[r] == 1) {
        cout << l << " " << r << " " << sum << endl;
      } else if (f[l] == 1) {
        f[r] = 1;
        sum -= r;
        cout << l << " " << r << " " << r << endl;
      } else if (f[r] == 1) {
        f[l] = 1;
        sum -= l;
        cout << l << " " << r << " " << l << endl;
      }
    }
  }
}
