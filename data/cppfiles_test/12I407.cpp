#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int rem = (n * m) / 2 - k;
    if ((n - k) % 2 != 0) {
      cout << "NO\n";
    } else if ((m - rem) % 2 != 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
