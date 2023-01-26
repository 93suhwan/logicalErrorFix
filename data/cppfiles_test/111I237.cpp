#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long MOD = 1e9 + 7;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j < i; j++) cout << "(";
      for (long long j = 0; j < i; j++) cout << ")";
      for (long long j = 0; j < n - i; j++) cout << "()";
    }
    cout << '\n';
  }
}
