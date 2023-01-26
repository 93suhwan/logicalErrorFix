#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int l = n + n * (n - 3) / 2;
    if (n % 2 == 0) {
      if (l > m) {
        if (n / 2 < k - 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        if (k > 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    } else {
      if (l > m) {
        if (n / 2 + 1 < k - 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        if (k > 1) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
  return 0;
}
