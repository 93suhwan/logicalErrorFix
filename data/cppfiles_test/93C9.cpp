#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0, current = 1;
    for (long long i = 1; i <= 1e18; i *= 2) {
      if (i > k) break;
      ans++;
      current += i;
    }
    cout << ans + (n - current) / k + (((n - current) % k) > 0) << endl;
  }
  return 0;
}
