#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, m, mod = 1e9 + 7;
  cin >> d;
  while (d--) {
    cin >> m;
    if (m == 1) {
      cout << 1 << endl;
      continue;
    }
    long long res = 1;
    m = m * 2;
    for (int i = m; i >= 1; i--)
      if (i != 2) res = (res * i) % mod;
    cout << res << endl;
  }
  return 0;
}
