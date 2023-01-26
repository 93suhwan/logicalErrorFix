#include <bits/stdc++.h>
using namespace std;
int nthroot(long long n) {
  for (int i = 1; i < 33; i++) {
    long long p = pow(i, 6);
    if (p == n) {
      return i;
    } else if (p > n) {
      return i - 1;
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long n1 = sqrt(n);
    long long n2 = cbrt(n);
    long long n3 = nthroot(n);
    long long ans = n1 + n2 - n3;
    cout << ans << endl;
  }
  return 0;
}
