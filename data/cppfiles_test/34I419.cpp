#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k;
int a[N];
struct node {
  int x, idx;
  int y;
  bool operator<(const node& k) const { return y < k.y; }
} val[N];
void solve() {
  long long ans = -99999999999;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i].x);
    val[i].idx = i;
    val[i].y = i - k * a[i];
  }
  sort(val + 1, val + 1 + n);
  long long ans1 = -99999999999;
  for (int i = 1; i < n; i++) {
    long long tem =
        1ll * val[i].idx * val[i + 1].idx - 1ll * k * (val[i].x | val[i + 1].x);
    ans1 = max(ans1, tem);
  }
  printf("%lld\n", ans1);
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
