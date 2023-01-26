#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long m, n, k;
  long long maxEdge;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    maxEdge = n * (n - 1) / 2;
    if (n == 1 && k > 1) {
      cout << "YES\n";
    } else if (m >= n - 1 && m <= maxEdge && k > 3) {
      cout << "YES\n";
    } else if (m == maxEdge && k > 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
