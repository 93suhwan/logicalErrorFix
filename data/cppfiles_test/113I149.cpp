#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long T;
  cin >> T;
  while (T--) {
    unsigned long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    unsigned long long num;
    if (x1 == x2) {
      if (p1 == p2)
        cout << "=\n";
      else if (p1 > p2)
        cout << ">\n";
      else
        cout << "<\n";
    } else {
      if (x1 > x2) {
        if (p1 >= p2)
          cout << ">";
        else {
          unsigned long long count = 0;
          num = x1 / x2;
          while (num != 0) {
            num = num / 10;
            count++;
          }
          if (count - 1 > p2 - p1)
            cout << ">\n";
          else if (count - 1 < p2 - p1) {
            cout << "<\n";
          } else {
            x2 = x2 * (pow(10, count - 1));
            if (x1 == x2)
              cout << "=\n";
            else if (x1 > x2)
              cout << ">\n";
            else
              cout << "<\n";
          }
        }
      } else {
        if (p2 >= p1)
          cout << "<";
        else {
          unsigned long long count = 0;
          num = x2 / x1;
          while (num != 0) {
            num = num / 10;
            count++;
          }
          if (count - 1 > p1 - p2)
            cout << "<\n";
          else if (count - 1 < p1 - p2) {
            cout << ">\n";
          } else {
            x1 = x1 * (pow(10, count - 1));
            if (x1 == x2)
              cout << "=\n";
            else if (x1 > x2)
              cout << ">\n";
            else
              cout << "<\n";
          }
        }
      }
    }
  }
  return 0;
}
