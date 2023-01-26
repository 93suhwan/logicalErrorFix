#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long c0 = 0, c1 = 0;
    s.erase(std::unique(s.begin(), s.end()), s.end());
    long long mx = 0;
    for (long long i = 0; i < s.size(); i++) {
      long long chk = s[i] - '0';
      if (chk & 1) {
        c1++;
      } else {
        c0++;
      }
      if (chk > mx) {
        mx = chk;
      }
    }
    cout << min(c0, (mx + 1)) << endl;
  }
}
