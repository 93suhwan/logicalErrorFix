#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
ll a[maxn];
ll sum[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    double ans = -1e12;
    for (int i = 1; i < n; i++) {
      ans = max(ans, (double)sum[i] / i + (double)(sum[n] - sum[i]) / (n - i));
    }
    cout << fixed << setprecision(9) << ans << endl;
  }
  return 0;
}
