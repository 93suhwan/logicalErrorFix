#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m < (n - 1))
      cout << "NO" << endl;
    else if (m > (n * (n - 1)) / 2)
      cout << "NO" << endl;
    else if (k <= 1)
      cout << "NO" << endl;
    else if (k == 2) {
      if (n == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (k == 3) {
      if (m == (n * (n - 1)) / 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
