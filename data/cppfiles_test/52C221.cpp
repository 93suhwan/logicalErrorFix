#include <bits/stdc++.h>
using namespace std;
long long binPow(long long a, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2)
    return binPow(a, n - 1) * a % 1000000007;
  else {
    long long b = binPow(a, n / 2);
    return b * b % 1000000007;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    cin >> n >> k;
    int l = 0;
    while (k != 0) {
      if (k % 2) ans = (ans + binPow(n, l)) % 1000000007;
      k /= 2;
      l++;
    }
    cout << ans << endl;
  }
}
