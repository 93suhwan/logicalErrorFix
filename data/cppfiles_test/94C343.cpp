#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0) {
      a = a * 10 + s[i] - '0';
    } else {
      b = b * 10 + s[i] - '0';
    }
  }
  if (min(a, b) == 0) {
    cout << max(a, b) - 1;
    return;
  }
  cout << (a + 1) * (b + 1) - 2;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
