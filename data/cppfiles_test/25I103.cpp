#include <bits/stdc++.h>
using namespace std;
bool sol(int i, string s, string t) {
  if (s[i] != t[0]) return false;
  int j = 0;
  while (i < s.size() && j < t.size() && s[i] == t[j]) i++, j++;
  if (j == t.size()) return true;
  i--, j--;
  while (i >= 0 && j < t.size() && s[i] == t[j]) i--, j++;
  if (j == t.size()) return true;
  return false;
}
void solve() {
  string s, t;
  cin >> s >> t;
  bool ans = false;
  for (int i = 0; i < s.size(); i++) {
    if (sol(i, s, t)) {
      ans = true;
      break;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
