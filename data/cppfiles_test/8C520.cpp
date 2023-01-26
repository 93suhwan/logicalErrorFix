#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x = n / 3;
    if (n % 3 == 0) {
      cout << x << " " << x << endl;
    } else if (n % 3 == 1) {
      cout << x + 1 << " " << x << endl;
    } else {
      cout << x << " " << x + 1 << endl;
    }
  }
  return 0;
}
