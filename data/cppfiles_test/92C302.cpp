#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (s[s.size() - 1] != s[0]) s[s.size() - 1] = s[0];
  cout << s << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
