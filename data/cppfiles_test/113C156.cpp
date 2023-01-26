#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long a[maxn];
struct node {
  long long x, y;
} b[maxn];
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> b[i].x >> b[i].y;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= m; i++) {
    long long ans = 0, ans1 = 0;
    int id = lower_bound(a + 1, a + 1 + n, b[i].x) - a;
    ans = max(0ll, b[i].x - a[id]) + max(0ll, b[i].y - sum + a[id]);
    if (id != 1) {
      id--;
      if (b[i].y - sum + a[id] > 0) ans1 += b[i].y - sum + a[id];
      ans1 += b[i].x - a[id];
    } else {
      ans1 = max(0ll, b[i].x - a[id]) + max(0ll, b[i].y - sum + a[id]);
    }
    cout << min(ans, ans1) << '\n';
  }
  return;
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
