#include <bits/stdc++.h>
const long long N = 1e3 + 2, MOD = 1e9 + 7;
using namespace std;
bool check(int n, int m, int k) {
  if (n <= 0 || m <= 0 || k < 0) {
    return false;
  }
  if (k == 0 && n % 2 == 0) {
    return true;
  }
  if (n * m < 2 * k) {
    return false;
  }
  bool flag = true;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0) {
      return true;
    } else {
      return false;
    }
  } else if (n % 2 == 0) {
    bool column = check(n, m - 2, k - n);
    if (column) {
      return true;
    }
  } else {
    bool row = check(n - 1, m, k - (m - k / 2));
    return row;
  }
  return false;
}
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
    if (check(n, m, k)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
