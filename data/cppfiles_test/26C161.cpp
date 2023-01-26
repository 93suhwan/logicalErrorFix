#include <bits/stdc++.h>
using namespace std;
long long fac(long long n) {
  long long ret = 1;
  for (long long i = 3; i <= n; i++) {
    ret = (ret * i) % 1000000007;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << fac(n * 2) << '\n';
  }
  return 0;
}
