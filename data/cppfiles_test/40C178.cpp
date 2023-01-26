#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, W, H, w, h, x1, y1, x2, y2, n, a1, a2, x, m = 0, k = 0;
  cin >> q;
  while (q > 0) {
    --q;
    cin >> n;
    if (n == 1) {
      cout << 0 << endl;
      for (int i = 0; i < n; i++) {
        cin >> x1 >> y1;
      }
    } else {
      vector<long long> a(n);
      vector<long long> b(n);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
      cin >> b[0];
      for (int i = 1; i < n; i++) {
        cin >> x;
        b[i] = b[i - 1] + x;
        a[n - 1 - i] += a[n - i];
      }
      k = min(a[1], b[n - 2]);
      for (int i = 1; i < n - 1; i++) k = min(k, max(a[i + 1], b[i - 1]));
      cout << k << endl;
    }
  }
  return 0;
}
