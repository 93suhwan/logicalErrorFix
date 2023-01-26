#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int zero = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      zero++;
    }
    if (s[i] == '0' and s[i - 1] == '0') {
      zero--;
    }
  }
  if (zero == 0) {
    cout << 0 << endl;
  } else if (zero == 1) {
    if (s.size() == 1)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  } else {
    cout << 2 << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
