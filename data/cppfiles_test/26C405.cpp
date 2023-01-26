#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tt = 0;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    long long int ans = 1;
    for (int i = 1; i <= 2 * n; i++) {
      if (i != 2) {
        ans = (ans * i) % 1000000007;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
