#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int x = 0, ind = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'b' && s[i - 1] == 'a') {
      x--;
      ind = i;
    } else if (s[i] == 'a' && s[i - 1] == 'b') {
      x++;
      ind = i;
    }
  }
  if (x == 0) {
    cout << s << endl;
  } else {
    if (x > 0) {
      s[s.size() - 1] = s[0];
    } else {
      s[0] = s[s.size() - 1];
    }
    cout << s << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
