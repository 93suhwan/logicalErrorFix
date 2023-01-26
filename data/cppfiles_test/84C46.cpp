#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 2e5 + 5;
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return res % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int x = n / 2;
    if (n % 2 == 1) x++;
    cout << (s) / (n - x + 1) << "\n";
  }
}
