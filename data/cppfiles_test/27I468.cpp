#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, edges, k, d = 0;
    cin >> n >> edges >> k;
    long long cmpGraph = n * (n - 1) / 2;
    if (edges > cmpGraph)
      d = INT_MAX;
    else if (edges == cmpGraph && edges > 0)
      d = 1;
    else if (edges >= n) {
      d = floor(edges / 2.0);
    } else {
      d = edges;
    }
    if (d < k - 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
