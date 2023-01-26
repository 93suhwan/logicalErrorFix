#include <bits/stdc++.h>
using namespace std;
long long ceildef(long long a, long long b) {
  return (long long)ceil(double(a) / (double)b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, m, i, j, a, b, ans = 1;
    cin >> n;
    if (n == 1)
      cout << "1\n";
    else {
      for (i = 3; i <= 2 * n; i++) {
        ans = (ans * i) % 1000000007;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
