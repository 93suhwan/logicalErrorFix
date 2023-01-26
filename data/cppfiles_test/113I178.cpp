#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long temp = min(p1, p2);
  p1 -= temp, p2 -= temp;
  if (x1 > x2 and p1 > p2) {
    cout << ">" << endl;
    return;
  }
  if (x1 < x2 and p1 < p2) {
    cout << "<" << endl;
    return;
  }
  if (x1 == x2 and p1 == p2) {
    cout << "=" << endl;
    return;
  }
  bool ch = false;
  if (p1 < p2) {
    ch = true;
    swap(x1, x2);
    swap(p1, p2);
  }
  while (p1) {
    if (x1 < x2) {
      x1 *= 10;
      p1--;
    } else if (x1 > x2) {
      if (!ch)
        cout << ">" << endl;
      else
        cout << "<" << endl;
      return;
    } else
      break;
  }
  if (x1 == x2)
    cout << "=" << endl;
  else if (x1 > x2) {
    if (!ch)
      cout << ">" << endl;
    else
      cout << "<" << endl;
  } else {
    if (!ch)
      cout << "<" << endl;
    else
      cout << ">" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
