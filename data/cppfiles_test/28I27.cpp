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
    int val = min({a, b, c});
    a -= val;
    b -= val;
    c -= val;
    val = min(a / 3, c);
    a -= 3 * val;
    c -= val;
    val = min(b / 3, c / 2);
    c -= 2 * val;
    b -= 3 * val;
    val = min(a / 2, b);
    a -= 2 * val;
    b -= val;
    int diff = func(a, b, c);
    cout << min(d1, diff) << "\n";
  }
}
