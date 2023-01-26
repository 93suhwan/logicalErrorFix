#include <bits/stdc++.h>
using namespace std;
const int maxn = 129;
int t, n, k;
long long a[maxn];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    long long ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n - 2 * k; i++) ans += a[i];
    for (int i = n - 2 * k + 1; i <= n - k; i++) ans += a[i] / a[i + k];
    cout << ans << '\n';
  }
  return 0;
}
