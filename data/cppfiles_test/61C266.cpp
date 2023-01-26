#include <bits/stdc++.h>
using namespace std;
struct item {
  int l, r, inc, dec;
};
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int last_ind = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R' || s[i] == 'B') {
      last_ind = i;
      for (int j = i - 1; j >= 0; j--) {
        if (s[j] != '?') break;
        s[j] = (s[j + 1] == 'R') ? 'B' : 'R';
      }
    }
  }
  if (last_ind != -1) {
    for (int i = last_ind + 1; i < n; i++) {
      s[i] = (s[i - 1] == 'R') ? 'B' : 'R';
    }
    cout << s << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        cout << 'B';
      else
        cout << "R";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
