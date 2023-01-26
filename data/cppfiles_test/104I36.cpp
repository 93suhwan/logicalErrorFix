#include <bits/stdc++.h>
using namespace std;
int T, a[200010], b[200010], l[200010], r[200010];
int main() {
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    long long suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      suma += a[i], sumb += b[i];
    }
    if (suma - n * m > sumb) {
      long long suml = 0, sumr = 0;
      for (int i = 1; i <= n; i++) {
        suml += max(0, m - a[i]);
        sumr += min(m, b[i]);
      }
      if (((suma - n * m) - sumb) / 2 >= suml &&
          ((suma - n * m) - sumb) / 2 <= sumr) {
        cout << ((suma - n * m) - sumb & 1) << endl;
        int v = ((suma - n * m) - sumb) / 2;
        for (int i = 1; i <= n; i++) {
          v -= max(0, m - a[i]);
        }
        for (int i = 1; i <= n; i++) {
          int l = max(0, m - a[i]), r = min(m, b[i]);
          if (v >= r - l) {
            v -= r - l;
            cout << max(0, m - b[i]) << " " << min(m, b[i]) << endl;
          } else {
            cout << m - v - l << " " << v + l << endl;
            v = 0;
          }
        }
      } else {
        cout << min(abs((suma - n * m) - (sumb - suml * 2)),
                    abs((suma - n * m) - (sumb - sumr * 2)))
             << endl;
        if (abs((suma - n * m) - (sumb - suml * 2)) <
            abs((suma - n * m) - (sumb - sumr * 2))) {
          for (int i = 1; i <= m; i++) {
            cout << min(m, a[i]) << " " << max(0, m - a[i]) << endl;
          }
        } else {
          for (int i = 1; i <= m; i++) {
            cout << max(0, m - b[i]) << " " << min(m, b[i]) << endl;
          }
        }
      }
    } else {
      long long suml = 0, sumr = 0;
      for (int i = 1; i <= n; i++) {
        suml += m - min(m, a[i]);
        sumr += m - max(0, m - b[i]);
      }
      if ((sumb - (suma - n * m)) / 2 >= suml &&
          (sumb - (suma - n * m)) / 2 <= sumr) {
        cout << (sumb - (suma - n * m) & 1) << endl;
        int v = (sumb - (suma - n * m)) / 2;
        for (int i = 1; i <= n; i++) {
          v -= m - min(m, a[i]);
        }
        for (int i = 1; i <= n; i++) {
          int l = m - min(m, a[i]), r = m - max(0, m - b[i]);
          if (v >= r - l) {
            v -= r - l;
            cout << max(0, m - b[i]) << " " << min(m, b[i]) << endl;
          } else {
            v = 0;
          }
        }
      } else {
        cout << min(abs(sumb - (suma - n * m + suml * 2)),
                    abs(sumb - (suma - n * m + sumr * 2)))
             << endl;
        if (abs(sumb - (suma - n * m + suml * 2)) <
            abs(sumb - (suma - n * m + sumr * 2))) {
          for (int i = 1; i <= m; i++) {
            cout << min(m, a[i]) << " " << max(0, m - a[i]) << endl;
          }
        } else {
          for (int i = 1; i <= m; i++) {
            cout << max(0, m - b[i]) << " " << min(m, b[i]) << endl;
          }
        }
      }
    }
  }
  return 0;
}
