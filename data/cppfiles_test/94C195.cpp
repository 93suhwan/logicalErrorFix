#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test_case() {
  string s, s1, s2;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i & 1)
      s2 += s[i];
    else
      s1 += s[i];
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1 << "\n";
    return;
  }
  cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
}
