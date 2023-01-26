#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k;
  cin >> t;
  int a[t];
  for (int i = 0; i < t; i++) {
    cin >> k;
    a[i] = k;
  }
  for (int i = 0; i < t; i++) {
    int p = sqrt(a[i]), dp = p * p;
    if (a[i] == p * p)
      cout << p << " " << 1 << endl;
    else if ((a[i] - dp) <= p)
      cout << a[i] - dp << " " << p + 1 << endl;
    else
      cout << p + 1 << " " << p + 1 - (a[i] - dp - p - 1) << endl;
  }
  return 0;
}
