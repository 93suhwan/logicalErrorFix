#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (m & 1) {
      if (m * n / 2 - k >= n / 2)
        cout << (k & 1 ? "NO" : "YES") << "\n";
      else
        cout << "NO\n";
    } else if (n & 1) {
      k = n * m / 2 - k;
      swap(n, m);
      if (m * n / 2 - k >= n / 2)
        cout << (k & 1 ? "NO" : "YES") << "\n";
      else
        cout << "NO\n";
    }
  }
}
