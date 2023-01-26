#include <bits/stdc++.h>
using namespace std;
int a[26];
int res = 1e9;
string str;
void fresh(char ch) {
  int l = 0, r = str.size() - 1;
  while (l < r) {
    while (l < r && str[l] == str[r]) {
      if (str[l] == ch) a[ch - 'a'] -= 2;
      ++l, --r;
    }
    if (l < r) {
      if (str[l] == ch)
        ++l;
      else if (str[r] == ch)
        --r;
      else
        return;
    }
  }
  if (l == r && str[l] == ch) a[ch - 'a']--;
  res = min(res, a[ch - 'a']);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> str;
    for (auto c : str) a[c - 'a']++;
    for (int i = 0; i < 26; ++i) fresh('a' + i);
    if (res == 1e9)
      cout << "-1\n";
    else
      cout << res << "\n";
    res = 1e9;
    memset(a, 0, sizeof a);
  }
}
