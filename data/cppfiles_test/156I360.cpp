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
    printf("%lld\n", min(k - a[0], 0ll));
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
  ll ans = LLONG_MAX;
  for (int i = 1; i < n; i++) {
    ll m;
    if (k - second[i] + a[0] >= 0) {
      m = (k - second[i] + a[0]) / (n - i);
    } else {
      m = -((second[i] - a[0] - k + n - i + 1) / (n - i));
    }
    ll need = 1ll * (n - i) + a[0] - m - 1;
    if (need < ans) {
      ans = need;
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
