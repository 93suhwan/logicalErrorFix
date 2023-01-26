#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.length();
    long long ncnt = 0;
    for (long long i = 0; i < n - 1; ++i) {
      ncnt += s[i] == 'N';
    }
    if (s[n - 1] == 'E') {
      if (ncnt != 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (ncnt >= 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
