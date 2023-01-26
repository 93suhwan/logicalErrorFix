#include <bits/stdc++.h>
using namespace std;
long long a[10005];
int b[10005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    k++;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] = pow(10ll, a[i]);
    long long ans = 0;
    for (int i = 1; i < n && k > 0; i++) {
      long long tmp = min(a[i + 1] / a[i] - 1, k);
      ans += tmp * a[i];
      k -= tmp;
    }
    ans += k * a[n];
    cout << ans << endl;
  }
  return 0;
}
