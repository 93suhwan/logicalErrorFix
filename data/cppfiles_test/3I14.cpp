#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int n = s.length();
  int ans = 0;
  if (n == 1) {
    if (s[0] == '0')
      printf("1\n");
    else
      printf("0\n");
    return 0;
  }
  for (int j = 0; j < 1000000000; j += 25) {
    int x = j;
    string t;
    while (x) {
      t += x % 10 + '0';
      x /= 10;
    }
    reverse(t.begin(), t.end());
    if (t.length() != n) continue;
    x = -1;
    bool ok = 1;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'X') {
        if (x == -1)
          x = t[j] - '0';
        else if (x != t[j] - '0')
          ok = 0;
      } else if ('0' <= s[j] && s[j] <= '9') {
        if (s[j] != t[j]) ok = 0;
      }
    }
    ans += ok;
  }
  printf("%d\n", ans);
}
