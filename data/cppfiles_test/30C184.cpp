#include <bits/stdc++.h>
using namespace std;
int checkPalindrome(string s, char c) {
  int n = s.length();
  int l = 0;
  int r = n - 1;
  int cnt = 0;
  while (l < r) {
    if (s[l] != s[r]) {
      while (l < n && s[l] == c) {
        l++;
        cnt++;
      }
      while (r >= 0 && s[r] == c) {
        r--;
        cnt++;
      }
      if (l < r && s[l] != s[r]) {
        return -1;
      }
    }
    l++;
    r--;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    map<char, int> mp;
    for (char c : s) {
      mp[c]++;
    }
    string t = s;
    reverse(t.begin(), t.end());
    if (t == s) {
      cout << "0\n";
      continue;
    }
    int res = 1e6;
    for (char c = 'a'; c <= 'z'; c++) {
      if (mp[c] != 0) {
        int cnt = checkPalindrome(s, c);
        if (cnt != -1) res = min(res, cnt);
      }
    }
    if (res == (int)1e6)
      cout << "-1\n";
    else
      cout << res << "\n";
  }
  return 0;
}
