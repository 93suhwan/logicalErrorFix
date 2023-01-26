#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long p1, x1, p2, x2, k1, k2;
  string s, t;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  while (x1 % 10 == 0) {
    x1 /= 10;
    p1++;
  }
  while (x2 % 10 == 0) {
    x2 /= 10;
    p2++;
  }
  s = to_string(x1);
  t = to_string(x2);
  k1 = s.length();
  k2 = t.length();
  while (k1 != k2) {
    if (k1 > k2) {
      t += '0';
      p2--;
      k2++;
    }
    if (k1 < k2) {
      s += '0';
      p1--;
      k1++;
    }
  }
  if (p1 == p2) {
    if (x1 > x2) {
      cout << ">" << endl;
    } else {
      if (x1 == x2)
        cout << "=" << endl;
      else
        cout << "<" << endl;
    }
  }
  if (p1 > p2)
    cout << ">" << endl;
  else
    cout << "<" << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
