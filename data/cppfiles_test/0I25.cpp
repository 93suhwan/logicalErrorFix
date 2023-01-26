#include <bits/stdc++.h>
using namespace std;
int t, ans = 0, tot = 0, kk = 0;
const int mxn = 2e7 + 10, mod = 1e9 + 7;
bool cmp(string s, string ss) {
  string s1, s2, ss1, ss2;
  int i;
  for (i = 0; i < s.size(); i += 2) s1 += s[i];
  for (i = 1; i < s.size(); i += 2) s2 += s[i];
  for (i = 0; i < ss.size(); i += 2) ss1 += ss[i];
  for (i = 1; i < ss.size(); i += 2) ss2 += ss[i];
  if (s1 == ss1) return s2 > ss2;
  return s1 < ss1;
}
signed main() {
  int n, m, a, b, c, d, e, i, j, k, sm = 0, sm1 = 0, cn = 0, cn1 = 0, mx = -1e9,
                                    mn = 1e9;
  string s, ss, sr, sa;
  bool f = false, ff = true;
  cin >> n >> m;
  string str[n];
  map<string, int> mp;
  for (i = 0; i < n; i++) cin >> str[i], mp[str[i]] = i + 1;
  sort(str, str + n, cmp);
  for (i = 0; i < n; i++) cout << mp[str[i]] << " ";
  cout << "\n";
}
