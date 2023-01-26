#include <bits/stdc++.h>
using namespace std;
int check(string& s, char c) {
  int i = 0, j = s.size() - 1;
  int sol = 0;
  while (i < j) {
    if (s[i] == s[j])
      ++i, --j;
    else if (s[i] != c && s[j] != c)
      return s.size() + 1;
    else if (s[i] == c) {
      ++i;
      ++sol;
    } else {
      --j;
      ++sol;
    }
  }
  return sol;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sol = n + 1;
  for (int i = 0; i < 26; i++) sol = min(check(s, (char)('a' + i)), sol);
  cout << (sol == n + 1 ? -1 : sol) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
