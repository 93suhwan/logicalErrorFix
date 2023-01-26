#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      sum += temp;
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
