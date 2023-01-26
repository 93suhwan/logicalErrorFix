#include <bits/stdc++.h>
using namespace std;
const long double err = 1e-7;
const long double pi = 3.1415926535897932384626433832795;
const long long rem = 1e17 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  for (long long te = 1; te <= tt; te++) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    long long zo = 0, oz = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0' and t[i] == '1')
        zo++;
      else if (s[i] == '1' and t[i] == '0')
        oz++;
    }
    long long ans = rem;
    if (oz == zo) ans = oz * 2;
    string s1 = s;
    for (long long i = 0; i < n; i++) {
      if (s1[i] == '1' and t[i] == '1') {
        for (long long j = 0; j < n; j++) {
          if (j == i) continue;
          s1[j] = (s1[j] == '1' ? '0' : '1');
        }
        break;
      }
    }
    zo = 0, oz = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] == '0' and t[i] == '1')
        zo++;
      else if (s1[i] == '1' and t[i] == '0')
        oz++;
    }
    if (oz == zo) ans = min(ans, 1 + oz * 2);
    string s2 = s;
    for (long long i = 0; i < n; i++) {
      if (s2[i] == '1' and t[i] == '0') {
        for (long long j = 0; j < n; j++) {
          if (j == i) continue;
          s2[j] = (s2[j] == '1' ? '0' : '1');
        }
        break;
      }
    }
    zo = 0, oz = 0;
    for (long long i = 0; i < n; i++) {
      if (s2[i] == '0' and t[i] == '1')
        zo++;
      else if (s2[i] == '1' and t[i] == '0')
        oz++;
    }
    if (oz == zo) ans = min(ans, 1 + oz * 2);
    cout << (ans == rem ? -1 : ans) << "\n";
  }
}
