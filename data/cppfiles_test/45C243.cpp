#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100009], cnt;
signed main() {
  cin >> t;
  while (t--) {
    long long ji = 0, ou = 0, k = 0, l = 1, cnt = 0, ant = 0, uu = 0, vv = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++)
      if (a[i] % 2)
        ji++;
      else
        ou++;
    if (fabs(ji - ou) > 1) {
      cout << "-1" << endl;
      continue;
    }
    if (ji >= ou) {
      for (long long i = 1; i <= n; i++)
        if (a[i] % 2) {
          cnt += fabs(i - (2 * k + 1));
          k++;
        } else {
          ant += fabs(i - 2 * l);
          l++;
        }
      cnt = min(cnt, ant);
      if (ji != ou) {
        cout << cnt << endl;
        continue;
      }
    }
    k = 0, l = 1;
    if (ji <= ou) {
      for (long long i = 1; i <= n; i++)
        if (a[i] % 2 == 0) {
          uu += fabs(i - (2 * k + 1));
          k++;
        } else {
          vv += fabs(i - 2 * l);
          l++;
        }
      uu = min(uu, vv);
      if (ji != ou) {
        cout << uu << endl;
        continue;
      }
    }
    cout << min(uu, cnt) << endl;
  }
}
