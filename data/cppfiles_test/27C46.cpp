#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1) {
      cout << "NO\n";
      continue;
    } else if (k <= 1) {
      cout << "NO\n";
    } else if (n == 1 && k > 1 && (n * (n - 1)) / 2 >= m) {
      cout << "YES\n";
    } else if (n == 1 && (n * (n - 1)) / 2 < m) {
      cout << "NO\n";
    } else if (m > (n * (n - 1)) / 2) {
      cout << "NO\n";
    } else {
      if (1 < k - 1 && ((n * (n - 1)) / 2 == m)) {
        cout << "YES\n";
      } else if (2 < k - 1 && ((n * (n - 1)) / 2 > m)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
