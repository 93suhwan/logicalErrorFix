#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
int T, n, m, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    if (m % 2 != 0) {
      swap(n, m);
      k = (n * m) / 2 - k;
    }
    if (n % 2 == 0) {
      if (k % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (k % (m / 2) != 0) {
        cout << "NO\n";
      } else if ((k / (m / 2)) % 2 == 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
  return 0;
}
