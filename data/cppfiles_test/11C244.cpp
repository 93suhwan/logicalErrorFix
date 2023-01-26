#include <bits/stdc++.h>
using namespace std;
string a[200005];
long long val[200005];
signed main() {
  long long T, n, i, j, k;
  cin >> T;
  while (T--) {
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (j = 0; j < 5; j++) {
      for (i = 1; i <= n; i++) {
        val[i] = 0;
        for (k = 0; k < a[i].size(); k++)
          if (a[i][k] - 'a' == j) val[i]++;
        val[i] = val[i] - (a[i].size() - val[i]);
      }
      sort(val + 1, val + n + 1, greater<long long>());
      long long sum = 0;
      for (i = 1; i <= n; i++) {
        sum += val[i];
        if (sum <= 0) break;
      }
      ans = max(ans, i - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
