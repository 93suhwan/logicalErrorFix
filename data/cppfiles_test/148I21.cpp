#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long w, h, x1, x2, y1, y2, i, ans = 0;
    cin >> w >> h;
    cin >> x1;
    int a[x1];
    for (i = 0; i < x1; i++) {
      cin >> a[i];
    }
    cin >> x2;
    int b[x2];
    for (i = 0; i < x2; i++) {
      cin >> b[i];
    }
    cin >> y1;
    int c[y1];
    for (i = 0; i < y1; i++) {
      cin >> c[i];
    }
    cin >> y2;
    int d[y2];
    for (i = 0; i < y2; i++) {
      cin >> d[i];
    }
    long long p = a[x1 - 1] - a[0];
    long long q = b[x2 - 1] - b[0];
    long long s = c[y1 - 1] - c[0];
    long long r = d[y2 - 1] - d[0];
    long long maxi = max(p, q);
    long long ma = max(r, s);
    if (w > h) {
      ans = maxi * h;
    } else {
      ans = ma * w;
    }
    cout << ans << endl;
  }
}
