#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long c0 = 0, c1 = 0;
    for (long long i = 0; i < s.size(); i++) {
      long long chk = s[i] - '0';
      if (chk & 1) {
        c1++;
      } else {
        c0++;
      }
    }
    if (c1 == 0) {
      cout << 1 << endl;
    } else if (c0 == 0) {
      cout << 0 << endl;
    } else {
      cout << min(c0, c1) << endl;
    }
  }
}
