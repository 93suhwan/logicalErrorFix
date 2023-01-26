#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k = 0;
    cin >> n;
    string s;
    cin >> s;
    long long a = 0, b = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
    }
    if (a == b) {
      k = 1;
      cout << 1 << " " << n << endl;
    } else {
      for (long long i = 0; i < n; i++) {
        if (k) break;
        for (long long j = i; j < n; j++) {
          if (s[j] == 'a')
            a++;
          else
            b++;
          if (a == b && (i + 1) != j) {
            cout << i + 1 << " " << j + 1 << endl;
            k = 1;
            break;
          }
        }
        a = 0;
        b = 0;
      }
    }
    if (k != 1) cout << -1 << " " << -1 << endl;
  }
  return 0;
}
