#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007LL;
long long int fac(long long int n) {
  long long int res = 1LL;
  if (n <= 2LL) return n;
  for (long long int i = 3LL; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res;
}
void _run() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  long long int ans = fac(2LL * n);
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    _run();
  }
}
