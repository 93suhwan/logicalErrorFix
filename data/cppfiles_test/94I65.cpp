#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, s1, s2, s3;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      s1 += s[i];
    } else if (i % 2 == 1) {
      s2 += s[i];
    }
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1;
    return;
  }
  cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
