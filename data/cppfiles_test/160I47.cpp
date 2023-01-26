#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int a1, b1;
  cin >> a1 >> b1;
  int a2, b2;
  cin >> a2 >> b2;
  if (a1 == a2 || b1 == b2) {
    cout << 0 << endl;
    return;
  }
  if (a1 == a && b1 != b) {
    cout << a1 - a2 << endl;
    return;
  } else if (a1 != a && b1 == b) {
    cout << b1 - b2 << endl;
    return;
  } else if (a1 == a && b1 == b) {
    cout << a1 - a2 << endl;
    return;
  } else if (a1 == 1 && b1 == 1) {
    cout << a1 - a2 << endl;
    return;
  }
  if (a1 < a2 && b1 < b2) {
    int d1 = abs(a2 - a1);
    int d2 = abs(b2 - b1);
    cout << min(d1, d2) << endl;
  } else if (a1 < a2 && b1 > b2) {
    int d1 = abs(a2 - a1);
    cout << d1 << endl;
  } else if (a1 > a2 && b1 < b2) {
    int d2 = abs(b2 - b1);
    cout << d2 << endl;
  } else if (a1 > a2 && b1 > b2) {
    if (a1 == b1 && a == b) {
      int d1 = abs(a - a1);
      int d2 = abs(b - b1);
      if (d1 < d2) {
        int d = abs(a - a1);
        b1 += d;
        int d11 = abs(a - a2);
        int d22 = abs(b1 - b2);
        cout << min(d11, d22) + d << endl;
      } else {
        int d = abs(b - b1);
        a1 += d;
        int d11 = abs(a1 - a2);
        int d22 = abs(b - b2);
        cout << min(d11, d22) + d << endl;
      }
    } else {
      int d1 = abs(a - a1);
      int d2 = abs(b - b1);
      int ans = 0;
      if (d1 < d2) {
        ans += abs(a - a1);
        a1 = a;
        b1 += ans;
        ans += abs(b - b1);
        a1 -= abs(b - b1);
        b1 = b;
        int d1 = abs(a1 - a2);
        int d2 = abs(b1 - b2);
        int d = min(d1, d2);
        ans += d;
        cout << ans << endl;
      } else {
        ans += abs(b - b1);
        b1 = b;
        a1 += ans;
        ans += abs(a - a1);
        b1 -= abs(a - a1);
        a1 = a;
        int d1 = abs(a1 - a2);
        int d2 = abs(b1 - b2);
        int d = min(d1, d2);
        ans += d;
        cout << ans << endl;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
