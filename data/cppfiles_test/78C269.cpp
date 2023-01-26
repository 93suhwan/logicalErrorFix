#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, l, r;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    long long x = r / 2;
    if (l > x)
      cout << r % l << endl;
    else
      cout << r % (x + 1) << endl;
  }
  return 0;
}
