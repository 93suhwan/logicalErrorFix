#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int inf = 1e9 + 5;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int slen = s.length();
    int tlen = t.length();
    if (tlen > slen) {
      cout << "No" << endl;
      continue;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int j = 0;
    bool f = 0;
    for (int i = 0; i < slen; ++i) {
      if (f) {
        f = 0;
        continue;
      }
      if (s[i] == t[j])
        ++j;
      else
        f = 1;
      if (j == tlen) break;
    }
    if (j == tlen)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
