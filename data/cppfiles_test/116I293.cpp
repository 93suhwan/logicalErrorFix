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
    int valcnt = 1, valend = 1;
    if (a[i] == 0) {
      valcnt = add(valcnt, dpcnt[a[i]]);
      valend = 0;
    } else if (a[i] == 1) {
      valcnt = add(dpcnt[a[i]], dpcnt[a[i] - 1]);
      valend = add(valend, dpend[a[i]]);
    } else {
      valcnt = add(dpcnt[a[i]], dpcnt[a[i] - 1]);
      valend = add(dpend[a[i]], dpcnt[a[i] - 2]);
    }
    ans = add(ans, add(valcnt, valend));
    dpcnt[a[i]] += valcnt;
    dpend[a[i]] += valend;
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
