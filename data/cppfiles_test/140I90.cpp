#include <bits/stdc++.h>
using namespace std;
int nthroot(long long n) {
  for (int i = 1; i < 33; i++) {
    if (pow(i, 6) >= n) return i;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long n1 = sqrt(n);
    long long n2 = cbrt(n);
    long long n3 = nthroot(n);
    long long ans = n1 + n2 - n3 + 1;
    if (n == 1) ans--;
    cout << ans << endl;
  }
  return 0;
}
