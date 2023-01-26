#include <bits/stdc++.h>
using namespace std;
string fn(string s, vector<int>& od) {
  string t = s;
  int cur = 0, n = od.size();
  int a[26];
  for (__typeof(26) i = (0) - ((0) > (26)); i != (26) - ((0) > (26));
       i += 1 - 2 * ((0) > (26)))
    a[i] = 1;
  while (cur < n) {
    a[od[cur]] = 0;
    for (auto it : s)
      if (a[it - 'a']) t += it;
    cur++;
  }
  return t;
}
void init() {}
void solve() {
  string s;
  cin >> s;
  s = '?' + s;
  int l = s.length(), n = 0;
  int pre[l][26];
  int a[26];
  for (__typeof(26) i = (0) - ((0) > (26)); i != (26) - ((0) > (26));
       i += 1 - 2 * ((0) > (26)))
    a[i] = 1;
  memset(pre, 0, sizeof(pre));
  for (__typeof(l) i = (1) - ((1) > (l)); i != (l) - ((1) > (l));
       i += 1 - 2 * ((1) > (l))) {
    int c = s[i] - 'a';
    if (a[c]) n++, a[c] = 0;
    for (__typeof(26) j = (0) - ((0) > (26)); j != (26) - ((0) > (26));
         j += 1 - 2 * ((0) > (26))) {
      if (j == c) pre[i][j] = 1;
      pre[i][j] += pre[i - 1][j];
    }
  }
  vector<int> order;
  for (__typeof(26) i = (0) - ((0) > (26)); i != (26) - ((0) > (26));
       i += 1 - 2 * ((0) > (26)))
    a[i] = 1;
  int f[26] = {};
  for (__typeof(1) i = (l) - ((l) > (1)); i != (1) - ((l) > (1));
       i += 1 - 2 * ((l) > (1))) {
    int c = s[i] - 'a';
    if (a[c]) {
      a[c] = 0;
      order.push_back(c);
      if (pre[i][c] % n) {
        cout << -1 << endl;
        return;
      }
      f[c] = pre[i][c] / n;
      n--;
    }
  }
  string pos, od;
  for (__typeof(l) i = (1) - ((1) > (l)); i != (l) - ((1) > (l));
       i += 1 - 2 * ((1) > (l))) {
    int c = s[i] - 'a';
    if (f[c] == 0) break;
    pos += s[i];
    f[c]--;
  }
  reverse((order).begin(), (order).end());
  for (int c : order) od += 'a' + c;
  string x = '?' + fn(pos, order);
  if (x == s)
    cout << pos << " " << od << endl;
  else
    cout << -1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  init();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
