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
    int r = s.size(), frq[26] = {};
    for (int i = 0; i < s.size(); ++i) frq[s[i] - 'a']++;
    for (int i = 0; i < 26; ++i)
      if (frq[i] > 2) r = r - frq[i] + 2;
    cout << r / 2 << '\n';
  }
  return 0;
}
