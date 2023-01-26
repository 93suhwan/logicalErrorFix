#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, s1, s2;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0)
      s1 += s[i];
    else if (i % 2 == 1)
      s2 += s[i];
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1 << endl;
    return;
  }
  cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
