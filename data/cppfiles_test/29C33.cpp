#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
long long b[300005][4];
int k = 0;
long long ans = 0;
void update(int u, int delta, int id) {
  while (u <= k) b[u][id] += delta, u += u & (-u);
}
long long get(int u, int id) {
  long long res = 0;
  while (u > 0) res += b[u][id], u -= u & (-u);
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], k = max(k, a[i]);
  for (int i = 1; i <= n; ++i) {
    ans += 1ll * (i - 1) * a[i];
    ans -= get(a[i], 1);
    for (int j = 0; j * a[i] <= k; ++j) {
      int r = a[i] * (j + 1) - 1;
      r = min(r, k);
      int l = a[i] * j;
      ans += get(r, 2) - get(l - 1, 2);
      ans -= 1ll * a[i] * j * (get(r, 3) - get(l - 1, 3));
    }
    for (int j = 1; j * a[i] <= k; ++j) update(j * a[i], a[i], 1);
    update(a[i], a[i], 2);
    update(a[i], 1, 3);
    printf("%lld ", ans);
  }
}
