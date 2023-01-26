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
    int final = n;
    for (char x = 'a'; x <= 'z'; x++) {
      string s2;
      for (auto &c : s) {
        if (c != x) s2 += c;
      }
      bool possible = isPalindrome(s2);
      if (!possible) continue;
      int ans = 0;
      int j = n - 1;
      int l = 0, r = 0;
      for (int i = 0; i - l < (n - ans) / 2; i++) {
        if (s[i] == x) {
          if (s[i] != s[(j - r) - (i - l)]) {
            ans++;
            l++;
          }
        }
        if (s[(j - r) - (i - l)] == x) {
          if (s[i] != s[(j - r) - (i - l)]) {
            ans++;
            r++;
          }
        }
      }
      final = min(final, ans);
    }
    if (final != n)
      cout << final << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
