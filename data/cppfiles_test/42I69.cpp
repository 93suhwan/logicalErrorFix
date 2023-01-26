#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct node {
  long long x, y, h;
};
struct node a[200005];
bool cmp(node A, node B) { return A.y < B.y; }
bool vis[200005];
long long tr[400005];
long long c[200005];
long long lowbit(long long k) { return k & -k; }
void xi(long long k, long long w) {
  while (k <= 400000) {
    tr[k] += w;
    k += lowbit(k);
  }
  return;
}
long long fi(long long k) {
  long long cnt = 0;
  while (k) {
    cnt += tr[k];
    k -= lowbit(k);
  }
  return cnt;
}
signed main() {
  long long ans = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld %lld", &a[i].x, &a[i].y);
    a[i].h = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  cin >> m;
  long long t1;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &t1);
    vis[t1] = 1;
  }
  long long num = 0, no;
  for (long long i = 1; i <= n; i++) {
    if (vis[a[i].h]) num++;
    if (num == m) {
      t1 = 0;
      ans++;
      for (long long j = 1; j < i; j++) {
        if (vis[a[j].h]) t1 = max(t1, a[j].x);
      }
      if (t1 > a[i].x) ans += fi(a[i].x) - fi(t1 + 1);
      break;
    }
    long long temp = fi(a[i].x);
    ans += temp + 1;
    xi(1, temp + 1);
    xi(a[i].x + 1, -temp - 1);
  }
  cout << ans;
  return 0;
}
