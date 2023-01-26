#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  string s;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> s;
    long long n = s.length();
    long long l = 0, r = 0, mex = 0;
    while (l < n) {
      r = l;
      if (s[l] == '0') {
        while (s[r] != '1' && r < n) {
          r++;
        }
        mex++;
      }
      if (mex == 2 || r == n) {
        break;
      }
      l = r + 1;
    }
    cout << mex << "\n";
  }
  return 0;
}
