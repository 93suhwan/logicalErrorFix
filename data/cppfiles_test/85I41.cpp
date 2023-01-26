#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
string s;
long long z, o, t;
inline void input() { cin >> s; }
inline void solve() {
  char x;
  int o = 0;
  x = s[0];
  bool t = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != x && t && o > 1) {
      cout << 2 << "\n";
      return;
    }
    if (s[i] != x) {
      t = 1;
      x = s[i];
    }
    if (s[i] == '1') o++;
  }
  if (t) {
    cout << 1 << "\n";
  } else {
    if (x == '0')
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  while (tc--) {
    input();
    solve();
  }
  return 0;
}
