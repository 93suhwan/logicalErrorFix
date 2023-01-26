#include <bits/stdc++.h>
using namespace std;
bool allCharactersSame(string s) {
  int n = s.length();
  for (int i = 1; i < n; i++)
    if (s[i] != s[0]) return false;
  return true;
}
signed main() {
  int n;
  const int letters = 26;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int n = str.size();
    vector<int> cnt(letters);
    for (int i = 0; i < n; ++i) cnt[str[i] - 'a']++;
    int ans = 0, k = 0;
    for (int i = 0; i < letters; ++i) {
      if (cnt[i] > 1)
        ans++;
      else if (cnt[i] == 1)
        k++;
    }
    ans += k / 2;
    cout << ans << "\n";
  }
  return 0;
}
