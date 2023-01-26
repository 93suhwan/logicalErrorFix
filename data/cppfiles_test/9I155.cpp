#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.size(); i++) {
    m[s[i]]++;
  }
  int r = 0;
  int rr = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    if (m[i] == 1)
      rr++;
    else if (m[i] >= 2 and m[i] <= 3) {
      r += m[i] / 2;
    }
  }
  int ans = r + rr / 2;
  if (ans) {
    cout << ans << endl;
  } else if (rr != 1) {
    cout << "1\n";
  } else
    cout << "0\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
