#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long res = n % 4;
    if (res == 1) {
      if (!(x % 2))
        cout << x - n << endl;
      else
        cout << x + n << endl;
    } else if (res == 2)
      cout << x + 1 << endl;
    else if (res == 3) {
      if (!(x % 2))
        cout << x - n + 1 << endl;
      else
        cout << x + n + 1 << endl;
    } else
      cout << x << endl;
  }
  return 0;
}
