#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    string w;
    int f[26] = {}, f2[26] = {};
    for (int i = n - 1; ~i; --i) {
      if (!f[s[i] - 'a']) {
        w += s[i];
      }
      ++f[s[i] - 'a'];
    }
    reverse(w.begin(), w.end());
    int p[26];
    for (int i = 0; i < w.size(); ++i) {
      p[w[i] - 'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
      --f[s[i] - 'a'];
      ++f2[s[i] - 'a'];
      bool ok = 1;
      for (int j = 0; j < 26; ++j) {
        if (f[j] || f2[j]) {
          ok &= f[j] == f2[j] * p[j];
        }
      }
      if (ok) {
        cout << s.substr(0, i + 1) << " " << w << "\n";
        goto hell;
      }
    }
    cout << "-1\n";
  hell:;
  }
  return 0;
}
