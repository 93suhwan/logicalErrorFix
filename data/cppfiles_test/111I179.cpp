#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 2;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < i; j++) {
        cout << "(";
      }
      for (long long k = 0; k < i; k++) {
        cout << ")";
      }
      for (long long p = 1; p <= n - i; p++) {
        cout << "()";
      }
    }
    cout << '\n';
  }
}
