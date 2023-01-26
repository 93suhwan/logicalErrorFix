#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long m, n, x, y, i, j, k, d;
    cin >> n >> m >> k;
    int flag = 0;
    d = k;
    x = n * (n - 1) / 2;
    if (x == m)
      d = 1;
    else if (x > m && m > n - 1)
      d = 2;
    if (d < k - 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
