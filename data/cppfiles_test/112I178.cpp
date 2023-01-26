#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c - 3 < d)
      cout << "NO";
    else if (a + b + c == d + 3)
      cout << "YES";
    else {
      long long int k =
          2 * (a + b + c) - min(a, min(b, c)) - 2 * max(a, max(b, c)) - 3;
      if ((a >= b && b >= c) || (c >= b && b >= a)) {
        if (a > b || c > b) k++;
      } else if ((b >= c && c >= a) || (a >= c && c >= b)) {
        if (b > c || a > c) k++;
      } else if ((b >= a && a >= c) || (c >= a && a >= b)) {
        if (b > a || c > a) k++;
      }
      if (a + b + c - 3 - k <= d)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
