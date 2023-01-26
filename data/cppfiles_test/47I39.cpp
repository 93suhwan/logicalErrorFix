#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 5;
int T, n, k;
long long ans, a[MaxN];
vector<long long> v1, v2;
inline void solve() {
  ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  v1.clear();
  v2.clear();
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      v1.push_back(a[i]);
    } else if (a[i] < 0) {
      v2.push_back(-a[i]);
    }
  }
  reverse(v1.begin(), v1.end());
  for (int i = 0; i < (int)v1.size(); i++) {
    if (i % k == 0) {
      ans += v1[i] * 2;
    }
  }
  for (int i = 0; i < (int)v2.size(); i++) {
    if (i % k == 0) {
      ans += v2[i] * 2;
    }
  }
  if (v1.empty()) {
    ans -= v2[0];
  } else if (v2.empty()) {
    ans -= v1[0];
  } else {
    ans -= max(v1[0], v2[0]);
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
