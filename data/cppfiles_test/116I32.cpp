#include <bits/stdc++.h>
const double PI = acos(-1);
const int N = 1e5 + 10;
const int M = 998244353;
long long add(long long a, long long b) { return ((a + b) % M + M) % M; }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dpcnt(n + 1);
  vector<int> dpend(n + 1);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      if (dpcnt[a[i]] == 0)
        dpcnt[a[i]] = 1;
      else
        dpcnt[a[i]] = add(dpcnt[a[i]], dpcnt[a[i]]);
    } else if (a[i] == 1) {
      dpcnt[a[i]] = add(dpcnt[a[i]], dpcnt[a[i] - 1]);
      if (dpend[a[i]] == 0)
        dpend[a[i]] = 1;
      else
        dpend[a[i]] = add(dpend[a[i]], dpend[a[i]]);
    } else {
      dpcnt[a[i]] = add(dpcnt[a[i]], dpcnt[a[i] - 1]);
      dpend[a[i]] = add(dpend[a[i]], dpcnt[a[i] - 2]);
    }
    ans = add(ans, add(dpcnt[a[i]], dpend[a[i]]));
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
