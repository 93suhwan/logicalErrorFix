#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool in[26];
    for (auto &x : s) in[x - 'a'] = true;
    int final = n;
    for (char x = 'a'; x <= 'z'; x++) {
      if (!in[x - 'a']) continue;
      int i = 0, j = n - 1;
      int ans = 0;
      bool possible = true;
      while (i <= j) {
        if (s[i] == s[j]) {
          i++;
          j--;
          continue;
        }
        if (s[i] == x) {
          ans++;
          i++;
          continue;
        }
        if (s[j] == x) {
          ans++;
          j--;
          continue;
        } else {
          possible = false;
          break;
        }
      }
      if (possible) final = min(final, ans);
    }
    if (final != n)
      cout << final << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
