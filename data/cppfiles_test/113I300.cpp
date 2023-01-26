#include <bits/stdc++.h>
using namespace std;
const int N = 100;
void solve() {
  long long n, x1, x2, p1, p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  if (p1 >= p2) {
    int x = p1 - p2;
    if (x > 6)
      cout << ">" << endl;
    else {
      for (int i = 1; i <= x; i++) {
        if (x1 > x2) {
          cout << ">" << endl;
          break;
        } else {
          x1 *= 10;
        }
      }
      if (x1 == x2) {
        cout << "=" << endl;
      } else if (x1 > x2) {
        cout << ">" << endl;
      } else if (x1 < x2) {
        cout << "<" << endl;
      }
    }
  }
  if (p1 < p2) {
    int x = p2 - p1;
    if (x > 6)
      cout << "<" << endl;
    else {
      for (int i = 1; i <= x; i++) {
        if (x1 < x2) {
          cout << "<" << endl;
          break;
        } else {
          x2 *= 10;
        }
      }
      if (x1 == x2) {
        cout << "=" << endl;
      } else if (x1 < x2) {
        cout << "<" << endl;
      } else if (x1 > x2) {
        cout << ">" << endl;
      }
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
