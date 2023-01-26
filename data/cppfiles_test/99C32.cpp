#include <bits/stdc++.h>
using namespace std;
long long x;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long x0, n;
    cin >> x0 >> n;
    long long add;
    if (x0 % 2 == 0) {
      if (n % 4 == 0) add = 0;
      if (n % 4 == 1) add = -n;
      if (n % 4 == 2) add = 1;
      if (n % 4 == 3) add = n + 1;
    } else {
      if (n % 4 == 0) add = 0;
      if (n % 4 == 1) add = n;
      if (n % 4 == 2) add = -1;
      if (n % 4 == 3) add = -(n + 1);
    }
    x0 += add;
    cout << x0 << endl;
  }
  return 0;
}
