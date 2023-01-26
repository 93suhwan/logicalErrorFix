#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return (res * res) * a;
  else
    return (res * res);
}
int main() {
  int t = 1;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int low = binpow(10, n - 1);
    int high = binpow(10, n) - 1;
    if (low == 1) low--;
    while (low % 25) low++;
    int ans = 0;
    for (; low <= high; low += 25) {
      string current = to_string(low);
      char xval = '-';
      bool can = 1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '_') continue;
        if (s[i] == 'X') {
          if (xval != '-' && xval != current[i]) {
            can = 0;
            break;
          }
          xval = current[i];
        } else if (s[i] != current[i]) {
          can = 0;
          break;
        }
      }
      ans += can;
    }
    cout << ans << endl;
  }
}
