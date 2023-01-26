#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  for (long long(t) = (1); (t) < (T + 1); (t)++) {
    long long x, p, x2, p2;
    cin >> x >> p >> x2 >> p2;
    if (p - p2 > 10) {
      cout << '>' << "\n";
    } else if (p2 - p > 10) {
      cout << '<' << "\n";
    } else {
      if (p > p2) {
        while (p != p2) {
          x *= 10;
          p--;
        }
        if (x > x2) {
          cout << '>' << "\n";
        } else if (x < x2) {
          cout << '<' << "\n";
        } else {
          cout << '=' << "\n";
        }
      } else {
        while (p != p2) {
          x2 *= 10;
          p2--;
        }
        if (x > x2) {
          cout << '>' << "\n";
        } else if (x < x2) {
          cout << '<' << "\n";
        } else {
          cout << '=' << "\n";
        }
      }
    }
  }
  return 0;
}
