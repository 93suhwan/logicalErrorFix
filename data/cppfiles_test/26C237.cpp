#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int mod = 1000000007;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int product = 1;
    for (long long int i = 1; i <= 2 * n; i++) {
      if (i == 2) continue;
      product = ((product % mod) * (i) % mod) % mod;
    }
    cout << (product) % mod << "\n";
  }
  return 0;
}
