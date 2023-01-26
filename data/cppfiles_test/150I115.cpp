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
  for (int c1 = 0; c1 < 3; c1++) {
    for (int i = 0; i < n; i++) {
      for (int t1 = 0; t1 <= min(a[i], c1); t1++) {
        int c3 = (a[i] - t1) / 3;
        int c2 = 0;
        bool posib = true;
        for (int j = 0; j < n; j++) {
          int m = a[j] - 3 * min(a[j] / 3, c3);
          if (m % 2 == 1 && !c1) {
            posib = false;
            break;
          }
          if (m % 2 == 0) {
            c2 = max(c2, m / 2 - (c1 == 2));
          } else {
            c2 = max(c2, (m - 1) / 2);
          }
        }
        if (!posib) continue;
        ans = min(ans, 0ll + c1 + c2 + c3);
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
