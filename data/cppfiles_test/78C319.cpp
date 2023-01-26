#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
const double expp = 1e-10;
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (a <= (b - 1) / 2 + 1)
      cout << (b - 1) / 2 << endl;
    else {
      cout << b - a << endl;
    }
  }
  return 0;
}
