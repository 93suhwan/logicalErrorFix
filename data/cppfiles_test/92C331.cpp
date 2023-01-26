#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] == 'b' && s[n - 1] == 'a') {
    s[0] = 'a';
  } else if (s[0] == 'a' && s[n - 1] == 'b') {
    s[n - 1] = 'a';
  }
  cout << s << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
