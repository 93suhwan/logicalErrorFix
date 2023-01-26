#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (m < n - 1 || m > n * (n - 1) / 2 || k < 3)
      cout << "NO\n";
    else if (k > 3 || m == n * (n - 1) / 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
