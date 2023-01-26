#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[101];
    cin >> s;
    long long l = strlen(s);
    if (l % 2 != 0)
      cout << "NO" << endl;
    else {
      long long res = l / 2;
      string ans = "YES";
      for (long long i = 0; i < res; i++) {
        if (s[i] != s[res + i]) {
          ans = "NO";
          break;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
