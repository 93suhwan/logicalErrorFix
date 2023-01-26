#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (s[0] != s[n - 1])
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
