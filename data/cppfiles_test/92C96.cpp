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
    s[s.length() - 1] = s[0];
    cout << s << endl;
  }
}
