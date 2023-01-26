#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
int q = 0, n = 0, dp[N] = {}, d[N] = {}, p[N] = {}, lcp[N][N] = {};
string s = "";
vector<string> v;
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
    p[i] = x;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) lcp[i][j] = 1e9;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) lcp[i][j] = min(lcp[i][j - 1], p[j - 1]);
  for (int i = 0; i <= n; i++) dp[i] = n - i;
}
void solve() {
  cin >> n >> s;
  init();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      dp[j] = max(dp[j], dp[i] + n - j - lcp[d[i]][d[j]]);
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) solve();
  return 0;
}
