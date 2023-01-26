#include <bits/stdc++.h>
using namespace std;
int solve(string &s) {
  int i = 0, j = s.size() - 1;
  char deleted = '#';
  int ans_real = INT_MAX;
  int ans = 0;
  bool can = true;
  while (i < j) {
    if (s[i] != s[j]) {
      if (deleted == '#') {
        deleted = s[i];
        i++, ans++;
      } else {
        if (s[i] == deleted)
          i++, ans++;
        else if (s[j] == deleted)
          j--, ans++;
        else {
          can = false;
          break;
        }
      }
    } else
      i++, j--;
  }
  if (can) ans_real = min(ans, ans_real);
  deleted = '#';
  can = true;
  ans = 0;
  i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      if (deleted == '#') {
        deleted = s[j];
        j--, ans++;
      } else {
        if (s[i] == deleted)
          i++, ans++;
        else if (s[j] == deleted)
          j--, ans++;
        else {
          can = false;
          break;
        }
      }
    } else
      i++, j--;
  }
  if (can) ans_real = min(ans_real, ans);
  return ans_real;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = solve(s);
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
