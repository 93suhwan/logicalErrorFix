#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
const int INF = 2e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, t, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (n % 2 == 1 && m % 2 == 0) {
      if (2 * k >= m) {
        k = k - m / 2;
      } else {
        cout << "NO" << '\n';
        continue;
      }
    } else if (n % 2 == 0 && m % 2 == 1) {
      k = n * m / 2 - k;
      if (2 * k >= n) {
        k = k - n / 2;
      } else {
        cout << "NO" << '\n';
        continue;
      }
    }
    if (k % 2 == 1) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}
