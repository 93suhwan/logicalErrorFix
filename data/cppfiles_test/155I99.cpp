#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2e5;
int v[NMAX];
pair<int, int> p[NMAX];
int ans[NMAX];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  string s;
  cin >> s;
  int len = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') p[len++] = {v[i], i};
  sort(p, p + len);
  len = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') ans[p[len].second] = ++len;
  int x = len;
  len = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') p[len++] = {v[i], i};
  sort(p, p + len);
  len = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') ans[p[len].second] = x + ++len;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
