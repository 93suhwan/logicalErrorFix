#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, poz = 1;
  cin >> n;
  string s = string(n * 2, '(');
  for (int i = 0; i < n; i++) s[i * 2 + 1] = ')';
  cout << s << '\n';
  for (int i = 0; i < n - 1; i++) {
    s[i * 2 + 1] = '(';
    s[i * 2 + 2] = ')';
    cout << s << '\n';
    s[i * 2 + 1] = ')';
    s[i * 2 + 2] = '(';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
