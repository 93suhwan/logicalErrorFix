#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 3;
int const M = 1e6 + 3;
int const mod = 1e9 + 7;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
void solve() {
  map<char, int> ar;
  int j = 0, ans = 0;
  string s, ss;
  cin >> s >> ss;
  for (char i = 0; i < s.size(); i++) {
    char x = s[i];
    ar[x] = i;
  }
  for (int i = 0; i < ss.size() - 1; i++) {
    char x = ss[i], y = ss[i + 1];
    ans += abs(ar[x] - ar[y]);
  }
  cout << ans;
}
int main() {
  fast();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
