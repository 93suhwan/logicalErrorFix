#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, k;
int a[maxn], ans[maxn];
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum % ((1 + n) * n / 2) != 0) {
      cout << "NO" << endl;
      continue;
    } else
      sum /= (1 + n) * n / 2;
    for (int i = 2; i <= n; i++) {
      if ((sum - (a[i] - a[i - 1])) % n != 0) goto _NO;
      ans[i] = (sum - (a[i] - a[i - 1])) / n;
      if (ans[i] <= 0) goto _NO;
    }
    if ((sum - (a[1] - a[n])) % n != 0) goto _NO;
    ans[1] = (sum - (a[1] - a[n])) / n;
    if (ans[1] <= 0) goto _NO;
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    continue;
  _NO:
    cout << "NO" << endl;
  }
  return 0;
}
