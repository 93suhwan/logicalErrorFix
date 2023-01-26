#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n % 2 == 1) {
    cout << "NO"
         << "\n";
  } else {
    string s1, s2;
    s1 = s.substr(0, n / 2);
    s2 = s.substr(n / 2, n / 2);
    if (s1 != s2) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
