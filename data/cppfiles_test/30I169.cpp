#include <bits/stdc++.h>
using namespace std;
int res = 1e8;
int a[26];
string str;
void refresh(char ch) {
  int l = 0, r = str.size() - 1;
  while (l < r) {
    if (str[l] == ch && str[r] == ch) a[ch - 'a'] -= 2, ++l, --r;
    if (str[l] == ch && str[r] != ch) ++l;
    if (str[r] == ch && str[l] != ch) --r;
    if (l >= r) break;
    if (str[l] != str[r])
      return;
    else
      ++l, --r;
  }
  if (l == r && str[l] == ch) a[ch - 'a']--;
  res = min(res, a[ch - 'a']);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> str;
    for (auto c : str) a[c - 'a']++;
    for (int i = 0; i < 26; ++i) refresh('a' + i);
    if (res == 1e9)
      cout << "-1\n";
    else
      cout << res << "\n";
    res = 1e8;
    memset(a, 0, sizeof a);
  }
}
