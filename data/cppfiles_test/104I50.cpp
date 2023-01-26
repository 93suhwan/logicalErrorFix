#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 20;
long long a[N], b[N];
long long ansL[N], ansR[N];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    long long zuo, you;
    zuo = you = 0;
    for (long long i = 1; i <= n; i++)
      cin >> a[i] >> b[i], zuo += a[i], you += b[i], ansL[i] = ansR[i] = 0;
    for (long long i = 1; i <= n; i++) {
      long long k = m;
      if (zuo >= you) {
        long long mid = (zuo - you);
        mid = min(mid, k);
        long long lef = (mid + (k - mid) / 2);
        long long rig = k - lef;
        long long helf = min(a[i], lef);
        lef -= helf;
        a[i] -= helf;
        ansL[i] += helf;
        long long helr = min(b[i], rig);
        rig -= helr;
        b[i] -= helr;
        ansR[i] += helr;
        if (lef) {
          ansR[i] += lef;
        } else
          ansL[i] += rig;
      } else {
        long long mid = (you - zuo);
        mid = min(mid, k);
        long long rig = (mid + (k - mid) / 2);
        long long lef = k - rig;
        long long helf = min(a[i], lef);
        lef -= helf;
        a[i] -= helf;
        ansL[i] += helf;
        long long helr = min(b[i], rig);
        rig -= helr;
        b[i] -= helr;
        ansR[i] += helr;
        if (lef) {
          ansR[i] += lef;
        } else
          ansL[i] += rig;
      }
      zuo -= ansL[i];
      you -= ansR[i];
    }
    for (long long i = 1; i <= n; i++) {
      if (zuo < you) {
        long long mid = you - zuo;
        long long need = min(mid, ansR[i]);
        ansR[i] -= need;
        ansL[i] += need;
        zuo += need;
        you -= need;
      } else if (zuo > you) {
        long long mid = zuo - you;
        long long need = min(mid, ansL[i]);
        ansR[i] += need;
        ansL[i] -= need;
        zuo -= need;
        you += need;
      }
    }
    cout << abs(zuo - you) << endl;
    for (long long i = 1; i <= n; i++)
      cout << ansL[i] << " " << ansR[i] << endl;
  }
}
