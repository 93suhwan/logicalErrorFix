#include <bits/stdc++.h>
using namespace std;
long long a[200001], b[200001];
int main() {
  int t;
  int i, j;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (i = 0; i < n; i++) cin >> a[i] >> b[i];
    long long A = 0, B = 0, Ap = 0, Bp = 0;
    long long tot = 0, sum = 0;
    for (i = 0; i < n; i++) {
      A += a[i] - (m - min(m, b[i]));
      Ap += m - min(m, b[i]);
      B += b[i] - (m - min(m, a[i]));
      Bp += m - min(m, a[i]);
      sum += m;
      tot += a[i] + b[i] - m;
    }
    if (A + A < tot) {
      cout << tot - (A + A) << endl;
      for (i = 0; i < n; i++) {
        cout << m - min(m, b[i]) << " " << min(m, b[i]) << endl;
      }
    } else if (B + B < tot) {
      cout << tot - (B + B) << endl;
      for (i = 0; i < n; i++) {
        cout << min(m, a[i]) << " " << m - min(m, a[i]) << endl;
      }
    } else {
      long long togo = A - tot / 2;
      cout << (tot & 1) << endl;
      for (i = 0; i < n; i++) {
        long long x = min(togo, min(m, b[i]));
        x = min(x, a[i] - (m - min(m, b[i])));
        togo -= x;
        cout << m - min(m, b[i]) + x << " " << min(m, b[i]) - x << endl;
      }
    }
  }
}
