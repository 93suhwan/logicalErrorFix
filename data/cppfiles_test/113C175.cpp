#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, p1, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int u = x1;
    int cnt1 = 0;
    int cnt2 = 0;
    while (u) {
      u /= 10;
      cnt1++;
    }
    u = x2;
    while (u) {
      u /= 10;
      cnt2++;
    }
    if (cnt1 + p1 < cnt2 + p2) {
      cout << "<"
           << "\n";
    } else if (cnt1 + p1 > cnt2 + p2) {
      cout << ">"
           << "\n";
    } else {
      if (cnt1 > cnt2) {
        for (int i = 0; i < cnt1 - cnt2; i++) {
          x2 *= 10;
        }
      } else {
        for (int i = 0; i < cnt2 - cnt1; i++) {
          x1 *= 10;
        }
      }
      if (x1 > x2)
        cout << ">"
             << "\n";
      else if (x1 == x2)
        cout << "="
             << "\n";
      else
        cout << "<"
             << "\n";
    }
  }
  return 0;
}
