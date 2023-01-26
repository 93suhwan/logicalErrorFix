#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t1;
  t1 = 1;
  cin >> t1;
  while (t1--) {
    string s, t;
    cin >> s >> t;
    long long n = s.length();
    long long m = t.length();
    if (n < m) {
      cout << "NO"
           << "\n";
      continue;
    }
    if (n == m) {
      if (s == t) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
      continue;
    }
    long long i = n - 1;
    long long j = m - 1;
    while (i >= 0 && j >= 0) {
      if (s[i] == t[j]) {
        --i;
        --j;
      } else {
        --i;
        --i;
      }
    }
    if (j == -1) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
