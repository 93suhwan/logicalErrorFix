#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
const int N = 2e5 + 5;
long long a[N];
long long power(long long x, long long y, long long m) {
  y = y % m;
  x %= m;
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x % mod + mod) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  a[0] = 1;
  a[1] = 1;
  long long m = 1000000000 + 7;
  for (long long i = 2; i < N; i++) {
    a[i] = ((a[i - 1] * i)) % m;
  }
  while (t--) {
    int n;
    cin >> n;
    cout << (a[2 * n] * power(2, m - 2, m)) % mod << endl;
  }
  return 0;
}
