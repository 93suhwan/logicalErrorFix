#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    string s;
    cin >> s;
    int frq[26] = {};
    for (int i = 0; i < s.size(); ++i) frq[s[i] - 'a']++;
    int r = 0;
    for (int i = 0; i < 26; ++i)
      if (frq[i] > 0) r++;
    if (r > s.size() / 2)
      cout << s.size() / 2 << '\n';
    else
      cout << r << '\n';
  }
  return 0;
}
