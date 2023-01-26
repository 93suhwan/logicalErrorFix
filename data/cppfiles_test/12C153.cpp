#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 and m % 2 == 0) {
      int t1 = (m / 2), t2 = (m / 2) * n;
      if (k >= t1 and k <= t2) {
        if (t2 % 2 == k % 2) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    } else if (n % 2 == 0 and m % 2 == 0) {
      int t1 = 0, t2 = (m / 2) * n;
      if (k >= t1 and k <= t2 and k % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      int new_k = ((n * m) / 2) - k;
      k = new_k;
      swap(n, m);
      int t1 = (m / 2), t2 = (m / 2) * n;
      if (k >= t1 and k <= t2) {
        if (t2 % 2 == k % 2) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
