#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    bool inc = true;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      inc &= a[i] > a[i - 1];
    }
    if (n % 2 == 0 or !inc) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
