#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long a = 0;
    long long b = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == 'A' || s[i] == 'C') {
        a = a + 1;
      } else {
        b = b + 1;
      }
    }
    if (a == b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
