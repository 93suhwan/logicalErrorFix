#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
int q = 0, n = 0, dp[N] = {}, d[N] = {}, t[2 * N] = {};
string s = "";
vector<string> v;
void build() {
  for (int x = n - 1; x; x--) t[x] = min(t[x << 1], t[x << 1 | 1]);
}
int query(int l, int r) {
  int res = 1e9;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, t[l++]);
    if (r & 1) res = min(res, t[--r]);
  }
  return res;
}
bool cmp(string s1, string s2) {
  for (int i = 0; i < min(s1.length(), s2.length()); i++)
    if (s1[i] != s2[i]) return s1[i] < s2[i];
  return s1.length() < s2.length();
}
void init() {
  v.clear();
  for (int i = 0; i < n; i++) v.push_back(s.substr(i, n - i));
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < n; i++) d[n - v[i].length()] = i;
  for (int i = 0; i < n - 1; i++) {
    int x = v[i].length();
    for (int j = 0; j < v[i].length(); j++)
      if (v[i + 1][j] > v[i][j]) {
        x = j;
        break;
      }
    t[n + i] = x;
  }
  t[n + n - 1] = 1e9;
  build();
  for (int i = 0; i <= n; i++) dp[i] = n - i;
}
void solve() {
  cin >> n >> s;
  init();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int x = query(d[i], d[j]);
      dp[j] = max(dp[j], dp[i] + n - j - x);
    }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) solve();
  return 0;
}
