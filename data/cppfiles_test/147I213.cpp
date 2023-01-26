#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string s;
  cin >> s;
  if (s[0] == s.back()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) Solve();
}
