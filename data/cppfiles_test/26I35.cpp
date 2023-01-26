#include <bits/stdc++.h>
using namespace std;
const long long mxsz = 1e2 + 7;
const long long mxnm = 3 + 7;
const long long inf = 1e9 + 1e2;
const long long mod = 1e9 + 7;
const long double pi = (long double)3.14159265358;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string t = s;
    for (long long i = 0; i < s.size(); i++) {
      if (i % 2 == 0 && s[i] == '?') {
        s[i] = '1';
      }
      if (i % 2 == 1 && s[i] == '?') {
        s[i] = '0';
      }
    }
    for (long long i = 0; i < t.size(); i++) {
      if (i % 2 == 1 && t[i] == '?') {
        t[i] = '1';
      }
      if (i % 2 == 0 && t[i] == '?') {
        t[i] = '0';
      }
    }
    long long f, k, a1, a2;
    f = k = a1 = a2 = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (i % 2 == 1 && s[i] == '1') f++;
      if (i % 2 == 0 && s[i] == '1') k++;
      if (abs(f - k) >= (10 - i) / 2) {
        a1 = i + 1;
        break;
      }
    }
    f = k = 0;
    for (long long i = 0; i < t.size(); i++) {
      if (i % 2 == 1 && t[i] == '1') f++;
      if (i % 2 == 0 && t[i] == '1') k++;
      if (abs(f - k) >= (10 - i) / 2) {
        a2 = i + 1;
        break;
      }
    }
    cout << min(a1, a2) + 1 << "\n";
  }
}
