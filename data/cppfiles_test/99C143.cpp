#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long q = n / 4;
    long long rm = n % 4;
    long long ans = q * 4 + 1;
    if (rm != 0) {
      bool odd = true;
      while (odd) {
        if (x % 2 == 0) {
          x = x - ans;
          ans++;
        } else {
          x = x + ans;
          ans++;
        }
        if (ans > n) {
          odd = false;
        }
      }
    }
    cout << x << "\n";
  }
  return 0;
}
