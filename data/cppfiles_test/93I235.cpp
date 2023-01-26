#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    long long st = 0;
    long long ch = 1;
    while (ch <= a) {
      st++;
      ch *= 2;
    }
    st--;
    ch /= 2;
    long long xr = a - ch;
    if (a == 2) {
      xr = 1;
    }
    long long p = xr ^ b;
    if (p == 0) {
      cout << a;
    } else if (p < a) {
      cout << a + 1;
    } else if (p == a) {
      cout << a + 2;
    } else {
      cout << a + 1;
    }
    cout << "\n";
  }
}
