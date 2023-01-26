#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
long long k;
int a[maxn];
long long pre[maxn];
long long check(long long x) {
  long long ans = a[1] - x;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    long long tmp = pre[mid];
    tmp += x * (n - mid);
    tmp -= ans;
    if (tmp <= k)
      l = mid + 1;
    else
      r = mid;
  }
  l -= 1;
  ans += (n - l);
  return ans;
}
void solve() {
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) ans += a[i];
  if (ans <= k) {
    cout << 0 << '\n';
    return;
  }
  sort(a + 1, a + 1 + n);
  pre[1] = a[1];
  for (int i = 2; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
  long long mi = k / n;
  if (mi * n > k) mi--;
  long long r = min(mi, 1ll * a[1]);
  long long l = -1e9 - maxn;
  while (l + 3 < r) {
    long long midl = (r - l) / 3 + l;
    long long midr = 2 * (r - l) / 3 + l;
    long long ansl = check(midl);
    long long ansr = check(midr);
    if (ansl > ansr) {
      l = midl;
    } else {
      r = midr;
    }
  }
  ans = 2e9 + 10;
  for (long long i = l; i <= r; ++i) {
    ans = min(ans, check(i));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
