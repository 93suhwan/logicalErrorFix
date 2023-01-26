#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
const int N = 2e5 + 3;
const int mod = 1e9 + 7;
ll a[N], second[N];
void solve() {
  int n;
  ll k;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  if (n == 1) {
    printf("%lld\n", max(a[0] - k, 0ll));
    return;
  }
  sort(a, a + n);
  second[0] = a[0];
  for (int i = 1; i < n; i++) {
    second[i] = second[i - 1] + a[i];
  }
  if (second[n - 1] <= k) {
    printf("0\n");
    return;
  }
  ll m = min(k / n, a[0]);
  ll ans = a[0] - m + (n - 1);
  for (int i = 1; i < n; i++) {
    ll m = k - second[i] + second[0];
    if (m < 0) {
      m *= -1;
      m = (m + (n - i) - 1) / (n - i);
      m *= -1;
    } else {
      m /= (n - i);
    }
    m = min(a[0], m);
    ans = min(ans, a[0] - m + (n - i - 1));
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
