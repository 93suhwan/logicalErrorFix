#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  long long fact[200009];
  fact[2] = 1;
  for (long long i = 3; i < 200009; i++)
    fact[i] = (1LL * fact[i - 1] % mod * i % mod) % mod;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = fact[2 * n] % mod;
    cout << ans % mod << "\n";
  }
}
