#include <bits/stdc++.h>
using namespace std;
int func(int a, int b, int c) {
  int diff;
  a = a % 2;
  b = b % 2;
  c = c % 2;
  if (a == 0 && b == 0 && c == 0) diff = 0;
  if (a == 0 && b == 0 && c == 1) diff = 3;
  if (a == 0 && b == 1 && c == 0) diff = 2;
  if (a == 0 && b == 1 && c == 1) diff = 1;
  if (a == 1 && b == 0 && c == 0) diff = 1;
  if (a == 1 && b == 0 && c == 1) diff = 2;
  if (a == 1 && b == 1 && c == 0) diff = 1;
  if (a == 1 && b == 1 && c == 1) diff = 0;
  return diff;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int d1 = func(a, b, c);
    int d, e, f;
    d = a, e = b, f = c;
    if (2 * d > e) {
      int v = e;
      e = 0;
      d -= 2 * v;
    } else {
      e -= a / 2;
      d = 0;
    }
    int d4 = func(d, e, f);
    if (min(a, b) > c) {
      int v = c;
      c = 0;
      a -= v;
      b -= v;
    } else {
      int v = min(a, b);
      a -= v;
      b -= v;
      c -= v;
    }
    int d2 = func(a, b, c);
    if (2 * a > b) {
      int v = b;
      b = 0;
      a -= 2 * v;
    } else {
      b -= a / 2;
      a = 0;
    }
    int d3 = func(a, b, c);
    int res = min({d1, d2, d3, d4});
    cout << res << "\n";
  }
}
