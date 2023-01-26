#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
void solve() {
  string s, tmp;
  cin >> s;
  int a = 0, b = 0;
  tmp = s[0];
  for (int i = 1; s[i] != '\0'; i++) {
    if (s[i] != s[i - 1]) tmp += s[i];
  }
  for (int i = 0; tmp[i] != '\0'; i++) {
    if (tmp[i] == '0')
      b++;
    else
      a++;
  }
  if (b) {
    if (b == 1) cout << 1 << endl;
    if (b >= 2) cout << 2 << endl;
  } else {
    cout << 0 << endl;
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
