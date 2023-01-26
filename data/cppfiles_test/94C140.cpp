#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, s1 = "", s2 = "", s3;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0) {
      s1 += s[i];
    } else if (i % 2 == 1) {
      s2 += s[i];
    }
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1;
  } else {
    int k1 = (stoi(s1) + 1);
    int k2 = (stoi(s2) + 1);
    cout << k1 * k2 - 2;
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
