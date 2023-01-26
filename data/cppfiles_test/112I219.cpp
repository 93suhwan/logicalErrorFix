#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int arr[5];
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    a--;
    b--;
    c--;
    bool flag = false;
    if (a + b + c > m) {
      if (m < a) {
        a -= m;
        b -= a;
        b++;
        c++;
        if (abs(c - abs(b)) <= 1)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else if (a == m) {
        if (abs(b - c) <= 1)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        m -= a;
        if (m < b) {
          b -= m;
          c -= b;
          c++;
          if (a == 0) a++;
          if (b == 0) b++;
          if (abs(c) <= 1 + a + b)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else if (m == b) {
          if (a == 0) a++;
          if (b == 0) b++;
          if (c <= 1 + a + b)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else {
          if (m < c) {
            if (a == 0) a++;
            if (b == 0) b++;
            c -= m;
            if (c <= a + b)
              cout << "YES" << endl;
            else
              cout << "NO" << endl;
          } else if (m == c)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        }
      }
    } else if (a + b + c == m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
