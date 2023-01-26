#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char c;
    cin >> c;
    string str;
    cin >> str;
    long long ctr = 0;
    long long k = 0;
    for (long long i = 0; i < n; i++) {
      if (str[i] != c) {
        ctr++;
        k = i;
      }
    }
    if (ctr == 0) {
      cout << 0;
    } else if (ctr == 1) {
      cout << 1 << "\n";
      cout << k + 1;
    } else {
      cout << 2 << "\n";
      cout << n << " " << n - 1;
    }
    cout << "\n";
  }
  return 0;
}
