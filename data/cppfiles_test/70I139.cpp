#include <bits/stdc++.h>
using namespace std;
char cntsrc[30];
pair<string, string> decode(string s) {
  memset(cntsrc, 0, sizeof(cntsrc));
  string order;
  reverse(s.begin(), s.end());
  for (auto c : s) {
    if (!cntsrc[c - 'a']) order.push_back(c);
    cntsrc[c - 'a']++;
  }
  int m = order.length();
  int originalLength = 0;
  for (int i = 0; i < m; i++)
    originalLength += cntsrc[order[i] - 'a'] / (m - i);
  reverse(order.begin(), order.end());
  return {string(s.rbegin(), s.rbegin() + originalLength), order};
}
string encode(pair<string, string> p) {
  string result = p.first;
  for (auto c : p.second) {
    string temp;
    for (auto d : p.first)
      if (d != c) {
        temp.push_back(d);
        result.push_back(d);
      }
    p.first = temp;
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto ans = decode(s);
    auto check = encode(ans);
    if (check == s)
      cout << ans.first << ' ' << ans.second << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
