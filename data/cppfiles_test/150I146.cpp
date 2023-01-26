#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
const int N = 101;
const int mod = 1e9 + 7;
int a[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  ll ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    vi v3 = {a[i] / 3};
    if (v3[0] >= 1) v3.push_back(v3[0] - 1);
    if (v3[0] >= 2) v3.push_back(v3[0] - 2);
    for (auto c3 : v3) {
      for (int j = 0; j < n; j++) {
        vi v2 = {(a[j] - 3 * min(a[j] / 3, c3)) / 2};
        if (v2[0] >= 1) v2.push_back(v2[0] - 1);
        if (v2[0] >= 2) v2.push_back(v2[0] - 2);
        for (auto c2 : v2) {
          int mxm = 0;
          for (int r = 0; r < n; r++) {
            int m = a[r];
            m = m - 3 * min(m / 3, c3);
            m = m - 2 * min(m / 2, c2);
            mxm = max(mxm, m);
          }
          ans = min(ans, 0ll + c2 + c3 + mxm);
        }
      }
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
