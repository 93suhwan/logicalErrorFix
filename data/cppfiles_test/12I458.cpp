#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % 2 != 0) {
      if (k >= m / 2) {
        if ((k - m / 2) % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    } else {
      if (k % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
