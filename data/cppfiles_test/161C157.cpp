#include <bits/stdc++.h>
using namespace std;
long long t, n, m, rb, cb, rd, cd, l, r;
long long ft[101000];
struct node {
  long long l, r, id;
  bool operator<(const node &ft) const { return r > ft.r; }
} a[10005], b[10005];
bool f[10005];
long long ans[101000];
bool cmp(node x, node y) {
  if (x.l == y.l) {
    return x.r < y.r;
  }
  return x.l < y.l;
}
priority_queue<node> q;
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0, cnt = 1, now = 1;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i].l >> a[i].r;
      b[i].l = a[i].l, b[i].r = a[i].r;
      a[i].id = i;
      f[i] = 0;
      sum += i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (long long i = 1; i <= n; i++) {
      while (a[now].l <= i && now <= n) {
        q.push(node{a[now].l, a[now].r, a[now].id});
        now++;
      }
      node t = q.top();
      q.pop();
      cout << b[t.id].l << " " << b[t.id].r << " " << cnt << endl;
      cnt++;
    }
  }
}
