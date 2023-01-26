#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, 1000000007 - 2ll); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ctr(30, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for (int j = 0; j < 30; j++) {
        ctr[j] += a % 2;
        a /= 2;
      }
    }
    int val = 0;
    for (int i = 0; i < 30; i++) {
      val = gcd(val, ctr[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (val % i == 0) cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
