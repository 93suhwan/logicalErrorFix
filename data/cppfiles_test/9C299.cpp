#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int x = s.size(), cnt = 0, cnt2 = 0;
    multiset<char> m;
    for (auto u : s) {
      m.insert(u);
    }
    for (char i = 0; i < 26; i++) {
      char c = i + 'a';
      if (m.count(c) == 1) cnt++;
      if (m.count(c) > 1) cnt2++;
    }
    cout << (cnt / 2) + cnt2 << '\n';
  }
  return 0;
}
