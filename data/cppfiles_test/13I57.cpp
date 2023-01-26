#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s;
  cin >> s;
  int len = s.size();
  if ((len % 2) || (len == 2)) return 0;
  if (len == 4) {
    if ((s[1] == 'B') && (s[2] == 'B') && (s[0] == 'A' || 'C') &&
        (s[3] == 'A' || 'C'))
      return 1;
    else
      return 0;
  } else {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else
        c++;
    }
    if (a + c == b)
      return 1;
    else
      return 0;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
