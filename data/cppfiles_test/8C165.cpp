#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
signed main() {
  long long T = 1;
  cin >> T;
  for (long long X = 1; X <= T; X++) {
    long long n;
    cin >> n;
    cout << n / 3 + (n % 3 == 1) << ' ' << n / 3 + (n % 3 == 2) << '\n';
  }
}
