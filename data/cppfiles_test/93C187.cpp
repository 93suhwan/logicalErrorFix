#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a = 0, c = 1;
    while (c < k) {
      c *= 2;
      a++;
    }
    a += (n - c + k - 1) / k;
    cout << a << "\n";
  }
  return 0;
}
