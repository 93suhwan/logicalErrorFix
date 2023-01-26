#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long maximum = max(a, b);
    maximum = max(maximum, c);
    int flag = -1;
    if (maximum == a) {
      if (a == (b + c)) flag = 1;
    }
    if (maximum == b) {
      if (b == (a + c)) flag = 1;
    }
    if (maximum == c) {
      if (c == (b + a)) flag = 1;
    }
    if (a == b && c % 2 == 0) flag = 1;
    if (c == b && a % 2 == 0) flag = 1;
    if (a == c && b % 2 == 0) flag = 1;
    if (flag == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
