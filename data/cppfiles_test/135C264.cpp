#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
long long a[maxn];
int main() {
  int _;
  cin >> _;
  while (_--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    long long ans = 0;
    for (int i = 1; i <= k; i++) ans += a[k + i] / a[i];
    for (int i = 2 * k + 1; i <= n; i++) ans += a[i];
    cout << ans << "\n";
  }
}
