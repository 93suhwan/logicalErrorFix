#include <bits/stdc++.h>
const long long N = 1e3 + 2, MOD = 1e9 + 7;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m < 2 * k) {
      cout << "NO\n";
      continue;
    }
    bool flag = true;
    if (n % 2 != 0) {
      int rows_filled = 2 * k / m;
      if (rows_filled > 0 && rows_filled % 2 != 0) {
        flag = true;
      } else {
        flag = false;
      }
    } else {
      int temp = k;
      if (k % 2 != 0) {
        flag = false;
      } else {
        int rows = 0;
        while (temp > m) {
          if (temp % 2) {
            flag = false;
            break;
          }
          temp = temp / 2;
          rows++;
        }
        if (flag) {
          if (rows % 2 == 0) {
            flag = true;
          } else {
            flag = false;
          }
        }
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
