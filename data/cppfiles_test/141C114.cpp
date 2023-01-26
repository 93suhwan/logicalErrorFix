#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, s;
    cin >> a >> s;
    long long int q = a, w = s;
    long long int a1, s1;
    long long int y = 0;
    long long int u = 1;
    long long int p = 0;
    while (q != 0) {
      a1 = q % 10;
      s1 = w % 100;
      if (0 <= s1 - a1 && s1 - a1 <= 9 && s1 >= 10) {
        q = q / 10;
        w = w / 100;
        p = (s1 - a1) * u + p;
        u = u * 10;
      } else {
        s1 = w % 10;
        if (0 <= s1 - a1 && s1 - a1 <= 9) {
          q = q / 10;
          w = w / 10;
          p = (s1 - a1) * u + p;
          u = u * 10;
        } else {
          y = 1;
          break;
        }
      }
    }
    p = w * u + p;
    if (y == 1)
      cout << -1 << endl;
    else
      cout << p << endl;
  }
  return 0;
}
