#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, edges, k, d = INT_MAX;
    cin >> n >> edges >> k;
    long long cmpGraph = n * (n - 1) / 2;
    bool valid = false;
    if (edges > cmpGraph) {
      valid = false;
    } else if (edges == cmpGraph) {
      d = (n == 1 ? 0 : 1);
    } else if (edges >= n - 1) {
      d = 2;
    } else if (edges == 0) {
      if (n == 1)
        d = 0;
      else
        valid = false;
    }
    if (d < k - 1) valid = true;
    cout << (valid ? "YES\n" : "NO\n");
  }
  return 0;
}
