#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-10;
int vis[50];
void solve() {
  string s, str, s1;
  cin >> s;
  int len = s.size();
  memset(vis, 0, sizeof(vis));
  for (int i = len - 1; i >= 0; i--) {
    if (!vis[s[i] - 'a']) str = s[i] + str;
    vis[s[i] - 'a']++;
  }
  int len2 = str.size();
  for (int i = 0; i < len2; i++) {
    if (vis[str[i] - 'a'] % (i + 1)) {
      cout << -1 << endl;
      return;
    }
    vis[str[i] - 'a'] /= (i + 1);
  }
  for (int i = 0; i < len; i++) {
    s1 += s[i];
    vis[s[i] - 'a']--;
    if (!vis[s[i] - 'a']) len2--;
    if (!len2) break;
  }
  string str1 = s1, str2 = s1;
  len2 = str.size();
  for (int i = 0; i < len2; i++) {
    str1.erase(std::remove(str1.begin(), str1.end(), str[i]), str1.end());
    s1 += str1;
  }
  if (s == s1)
    cout << str2 << ' ' << str << endl;
  else
    cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
