#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long A[N], sum[N], dif[N], dif1[N], ans[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    if (i > 1) sum[i] = A[i] - A[i - 1];
  }
  sum[1] = A[1] - A[n];
  for (int i = 2; i <= n; ++i) {
    dif[i] = sum[i - 1] - sum[i];
    if (dif[i] % n) {
      cout << "NO\n";
      return;
    }
    dif[i] /= n;
  }
  for (int i = 2; i <= n; ++i) {
    dif1[i] = dif1[i - 1] + dif[i];
  }
  long long k = 1, b = 0;
  for (int i = 2; i <= n; ++i) {
    k += (n - i + 2);
    b += dif1[i] * (n - i + 2);
  }
  if ((A[1] - b) % k) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  ans[1] = (A[1] - b) / k;
  for (int i = 1; i <= n; ++i) {
    ans[i] = ans[1] + dif1[i];
    if (ans[i] < 1) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[1] + dif1[i] << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
