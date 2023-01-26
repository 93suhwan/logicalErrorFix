#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    long long n, m, k;
    cin >> n >> m >> k;
    k -= 2;
    if (m >= n - 1 && (m <= (n * (n - 1) / 2))) {
      if (k <= -1) {
        cout << "NO" << endl;
      } else if (k >= 2) {
        cout << "YES" << endl;
      } else if (k == 1) {
        if (m == n * (n - 1) / 2) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else if (k == 0) {
        if (n == 1) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
