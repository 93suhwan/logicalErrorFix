#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    string a = s.substr(0, i + 1);
    string b = s.substr(0, i);
    reverse(b.begin(), b.end());
    a += b;
    if (a.find(t) != a.npos) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
