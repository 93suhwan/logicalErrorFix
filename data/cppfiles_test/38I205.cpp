#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    }
    long long int ans = min(
        {(n % 6), (n % 8), (n % 10), (n % 14), (n % 18), (n % 16), (n % 24)});
    ans += n;
    cout << ans * 2.5 << endl;
  }
  return 0;
}
