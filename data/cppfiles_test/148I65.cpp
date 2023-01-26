#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h;
  int n1, n2, n3, n4;
  int res = 0;
  cin >> w >> h;
  cin >> n1;
  int a[n1];
  for (int i = 0; i < n1; i++) {
    cin >> a[i];
  }
  cin >> n2;
  int b[n2];
  for (int i = 0; i < n2; i++) {
    cin >> b[i];
  }
  cin >> n3;
  int c[n3];
  for (int i = 0; i < n3; i++) {
    cin >> c[i];
  }
  cin >> n4;
  int d[n4];
  for (int i = 0; i < n4; i++) {
    cin >> d[i];
  }
  int x1, y1, x2, y2, x3, y3;
  x1 = a[0];
  y1 = 0;
  x2 = a[n1 - 1];
  y2 = 0;
  for (int i = 0; i < n2; i++) {
    x3 = b[i];
    y3 = h;
    res = max(res, abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
  }
  x1 = b[0];
  y1 = h;
  x2 = b[n2 - 1];
  y2 = h;
  for (int i = 0; i < n1; i++) {
    x3 = a[i];
    y3 = 0;
    res = max(res, abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
  }
  x1 = 0;
  y1 = c[0];
  x2 = 0;
  y2 = c[n3 - 1];
  for (int i = 0; i < n4; i++) {
    x3 = w;
    y3 = d[i];
    res = max(res, abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
  }
  x1 = w;
  y1 = d[0];
  x2 = w;
  y2 = d[n4 - 1];
  for (int i = 0; i < n3; i++) {
    x3 = 0;
    y3 = c[i];
    res = max(res, abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
  }
  cout << res << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
