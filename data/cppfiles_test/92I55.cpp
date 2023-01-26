#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0, s = 1;
  while (c < '0' || c > '9') {
    if (c == '-') s = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * s;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long sumab = 0, sumba = 0;
    for (long long i = 1; i < s.length(); i++) {
      if (s[i] == 'b' && s[i - 1] == 'a') sumab++;
      if (s[i] == 'a' && s[i - 1] == 'b') sumba++;
    }
    if (sumab == sumba) {
      cout << s << endl;
      continue;
    }
    if (sumab > sumba) {
      for (long long i = 1; i < s.length(); i++) {
        if (s[i] == 'b' && s[i - 1] == 'a') {
          s[i - 1] = 'b';
          sumab--;
        }
        if (sumab == sumba) break;
      }
      cout << s << endl;
      continue;
    } else {
      for (long long i = 1; i < s.length(); i++) {
        if (s[i] == 'a' && s[i - 1] == 'b') {
          s[i] = 'b';
          sumba--;
        }
        if (sumab == sumba) break;
      }
      cout << s << endl;
      continue;
    }
  }
}
