#include <bits/stdc++.h>
using namespace std;
long long f[100009], t, n, a, b, cnt, ant, w, u;
signed main() {
  cin >> t;
  while (t--) {
    cnt = 0, ant = 0, u = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> f[i];
    for (long long i = 0; i < n; i++)
      if (f[i] % 2)
        cnt++;
      else
        ant++;
    if (cnt < ant) swap(cnt, ant);
    if (cnt - ant > 1) {
      cout << -1 << endl;
      continue;
    }
    cnt = 0, ant = 1;
    w = 0;
    while (ant) {
      w = 0;
      ant = 0;
      for (long long i = 1; i < n - 1; i++)
        if ((f[i] - f[i - 1]) % 2 == 0 && (f[i + 1] - f[i]) % 2 != 0) {
          swap(f[i], f[i + 1]);
          cnt++;
          w = 1;
          break;
        }
      for (long long i = 0; i < n - 1; i++) {
        if ((f[i + 1] - f[i]) % 2 == 0) ant++;
      }
      if (ant && w == 0) {
        u = 1;
        break;
      }
    }
    if (u) {
      cnt = 0;
      while (ant) {
        ant = 0;
        for (long long i = n - 2; i > 0; i--)
          if ((f[i] - f[i - 1]) % 2 != 0 && (f[i + 1] - f[i]) % 2 == 0) {
            swap(f[i], f[i - 1]);
            cnt++;
            w = 1;
            break;
          }
        for (long long i = 0; i < n - 1; i++) {
          if ((f[i + 1] - f[i]) % 2 == 0) ant++;
        }
      }
    }
    cout << cnt << endl;
  }
}
