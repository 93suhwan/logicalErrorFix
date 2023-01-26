#include <bits/stdc++.h>
using namespace std;
int t, n, p;
long long a[200001], ans, d;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    p = 1;
    ans = a[0];
    d = a[0];
    while (p < n) {
      a[p] -= d;
      ans = max(ans, a[p]);
      d += a[p];
      p++;
    }
    cout << ans << endl;
  }
  return 0;
}
