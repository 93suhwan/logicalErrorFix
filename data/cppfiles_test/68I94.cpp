#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int k;
    cin >> k;
    int p = sqrt(k), dp = p * p;
    if (k == p * p)
      cout << p << " " << p << endl;
    else if ((k - dp) <= p)
      cout << k - dp << " " << p + 1 << endl;
    else
      cout << p + 1 << " " << p + 1 - (k - dp - p - 1) << endl;
    t--;
  }
  return 0;
}
