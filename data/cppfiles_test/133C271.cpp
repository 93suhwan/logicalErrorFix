#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int i, j, k, n, m, T;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    string s, ans = "", last;
    for (i = 1; i <= n - 2; i++) {
      cin >> s;
      if (i == 1)
        ans += s;
      else {
        if (last[1] != s[0])
          ans += s;
        else
          ans += s[1];
      }
      last = s;
    }
    if (ans.size() != n) ans += 'a';
    cout << ans << endl;
  }
  return 0;
}
