#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = ((n + 5) / 6) * 15;
    if (n % 6 != 0 && n > 6) {
      long long int m = n % 6;
      if (m <= 2)
        ans += 20 - 30;
      else if (m <= 4)
        ans += 25 - 30;
    }
    cout << ans << "\n";
  }
  return 0;
}
