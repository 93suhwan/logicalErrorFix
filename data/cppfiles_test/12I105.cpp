#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, m, k;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    if (n % 2 == 1) k = n * m / 2 - k;
    if (k % 2 == 0 && k <= m * n / 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
