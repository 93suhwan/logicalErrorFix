#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m % 2 == 0) {
      swap(n, m);
      k = n * m / 2 - k;
    }
    if (n % 2 == 0)
      cout << (k % 2 == 0 ? "YES\n" : "NO\n");
    else
      cout << (k >= m / 2 && k % 2 == (m / 2) % 2) << endl;
  }
  return 0;
}
