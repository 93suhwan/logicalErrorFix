#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char ch;
    vector<char> str[26];
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
      for (int j = 0; j < 26; j++) {
        ch = 'a' + j;
        if (ch == s[i])
          continue;
        else
          str[j].push_back(s[i]);
      }
    }
    int flag = 0, ans = 1e6;
    for (int i = 0; i < 26; i++) {
      vector<char> fk1, fk2;
      fk1 = str[i];
      char ch = 'a' + i;
      reverse(fk1.begin(), fk1.end());
      fk2 = fk1;
      reverse(fk1.begin(), fk1.end());
      s = s + 'X';
      if (fk1 == fk2) {
        flag = 1;
        int total = mp[ch];
        int p = 0;
        vector<int> v;
        for (int i = 0; i <= n; i++) {
          if (s[i] == ch)
            p++;
          else {
            v.push_back(p);
            p = 0;
          }
        }
        int sum = 0;
        for (int i = 0; i < (v.size() / 2); i++) {
          sum = sum + 2 * (min(v[i], v[v.size() - 1 - i]));
        }
        if (v.size() % 2 != 0) {
          sum = sum + (v[v.size() / 2]);
        }
        ans = min(ans, total - sum);
      }
    }
    if (flag == 1)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
