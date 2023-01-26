#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long m, n, x, y, i, j, k;
    cin >> n >> m >> k;
    int flag = 0;
    if (m < n - 1 || m > n * (n - 1) / 2)
      cout << "NO\n";
    else {
      if (n == 1 && m < k - 1)
        cout << "YES\n";
      else if (m == n * (n - 1) / 2 && k - 2 >= 1)
        cout << "YES\n";
      else if (k - 2 >= 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
