#include <bits/stdc++.h>
using namespace std;
long long int a[100];
long long int fastpow(long long int a, long long int n) {
  long long int base = a;
  long long int res = 1;
  while (n) {
    if (n & 1) res *= base;
    base *= base;
    n >>= 1;
  }
  return res;
}
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int y = 0, l = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        y++;
      else if (a[i] == 0)
        l++;
    }
    if (y == 0)
      cout << 0 << endl;
    else if (l == 0)
      cout << y << endl;
    else
      cout << y * fastpow(2, l) << endl;
  }
}
