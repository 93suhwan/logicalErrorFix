#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 0;
    for (int i = 0; i <= n / 2; ++i) {
      if (s[i] != s[n - 1 - i]) {
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << 0 << '\n';
      continue;
    }
    char a;
    for (int i = 0; i < 26; ++i) {
      ok = 0;
      string s1 = "";
      for (int j = 0; j < n; ++j) {
        if (s[j] == 'a' + i) {
          continue;
        }
        s1.push_back(s[j]);
      }
      for (int k = 0; k <= s1.size() / 2; ++k) {
        if (s1[k] != s1[s1.size() - 1 - k]) {
          ok = 1;
          break;
        }
      }
      if (!ok) {
        a = 'a' + i;
        break;
      }
    }
    if (ok) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i < j) {
      if (s[i] == a and s[i] != s[j]) {
        ans++;
        i++;
      } else if (s[j] == a and s[i] != s[j]) {
        ans++;
        j--;
      } else {
        i++;
        j--;
      }
    }
    cout << ans << '\n';
  }
}
