#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int arr[5];
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    bool flag = false;
    if ((a - 1) + (b - 1) + (c - 1) > m) {
      if (m < (a - 1)) {
        a--;
        a -= m;
        b -= a;
        if (abs(c - abs(b)) <= 1)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else if ((a - 1) == m) {
        if (abs(b - c) <= 1)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        m -= (a - 1);
        if (m < (b - 1)) {
          b--;
          b -= m;
          c -= b;
          if (abs(c) <= 1)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else if (m == (b - 1)) {
          if (c <= 1)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else {
          if (m < (c - 1)) {
            c -= m;
            c--;
            if (c == 0)
              cout << "YES" << endl;
            else
              cout << "NO" << endl;
          } else if (m == (c - 1))
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        }
      }
    } else if ((a - 1) + (b - 1) + (c - 1) == m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
