#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long mod = 1000000007;
    long long ans = 1;
    for (long long i = 3; i <= 2 * n; i++) {
      ans = (ans * i) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
