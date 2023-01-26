#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long x = 2;
    for (long long i = 1; i <= n; i++) {
      cout << x << " ";
      x++;
    }
    cout << "\n";
  }
  return 0;
}
