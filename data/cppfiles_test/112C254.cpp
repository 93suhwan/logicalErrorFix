#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  int t, a, b, c, m;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> m;
    int num[3] = {0}, sum = 0;
    if (a > 0) sum++;
    if (b > 0) sum++;
    if (c > 0) sum++;
    if (a >= b && a >= c) {
      if (b >= c)
        num[0] = a, num[1] = b, num[2] = c;
      else
        num[0] = a, num[1] = b, num[2] = c;
    } else if (b >= a && b >= c) {
      if (a >= c)
        num[0] = b, num[1] = a, num[2] = c;
      else
        num[0] = b, num[1] = c, num[2] = a;
    } else {
      if (a >= b)
        num[0] = c, num[1] = a, num[2] = b;
      else
        num[0] = c, num[1] = b, num[2] = a;
    }
    if (m > a + b + c - sum || num[0] - num[1] - num[2] - 1 > m)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
