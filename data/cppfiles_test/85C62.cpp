#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
string s;
long long z, o, t;
inline void input() { cin >> s; }
inline void solve() {
  z = 0;
  t = 0;
  char x = '0';
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == x)
      z = 1;
    else if (z == 1) {
      t++, z = 0;
    }
  }
  int n = s.size() - 1;
  (s[n] == x) ? t++ : t;
  if (t > 2) return void(cout << 2 << "\n");
  return void(cout << t << "\n");
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
