#include <bits/stdc++.h>
using namespace std;
signed main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << n + 1 << "\n";
  }
}
