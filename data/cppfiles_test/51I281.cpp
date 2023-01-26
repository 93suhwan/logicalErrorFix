#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 2) cout << -1 << " " << 2 << endl;
    if (n % 2 == 1)
      cout << n / 2 << " " << n / 2 + 1 << endl;
    else if (n != 2) {
      for (int i = 2; i <= n; i++) {
        if ((n - i * (i - 1) / 2) % i == 0) {
          cout << (n - i * (i - 1) / 2) / i << " "
               << i - 1 + (n - i * (i - 1) / 2) / i << endl;
          break;
        }
      }
    }
  }
}
