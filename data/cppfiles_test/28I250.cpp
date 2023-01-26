#include <bits/stdc++.h>
using namespace std;
long long abs1(long long x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long tempa = a, tempb = b, tempc = c;
    long long one = 2 * tempb, two = 3 * tempc;
    long long over = one - two;
    long long k = 0;
    int flag = 1;
    if (over > 0) {
      k = (over / 4.0) + 0.5;
      one -= 2 * k;
      two += 2 * k;
      if (abs1(one - two) >= a) {
        cout << abs1(one - two) - a << endl;
      } else if (a - (abs1(one - two)) & 1) {
        cout << 1 << endl;
      } else
        cout << 0 << endl;
    } else if (over < 0) {
      k = (abs1(over) / 6.0) + 0.5;
      one += 3 * k;
      two -= 3 * k;
      if (abs1(one - two) >= a) {
        cout << abs1(one - two) - a << endl;
      } else if (a - (abs1(one - two)) & 1) {
        cout << 1 << endl;
      } else
        cout << 0 << endl;
    } else if (over == 0) {
      if (a & 1) {
        cout << 1 << endl;
      } else
        cout << 0 << endl;
    }
  }
  return 0;
}
