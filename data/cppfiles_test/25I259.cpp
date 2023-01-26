#include <bits/stdc++.h>
using namespace std;
int q;
string s, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> s;
    cin >> t;
    int j = 0;
    int p = -1;
    for (int i = 0; i < s.size() && j != t.size(); ++i)
      if (s[i] == t[j]) {
        j++;
        p = i;
      }
    for (int i = p - 1; i >= 0 && j != t.size(); --i)
      if (s[i] == t[j]) j++;
    if (j == t.size())
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
