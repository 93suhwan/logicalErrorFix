#include <bits/stdc++.h>
using namespace std;
int memo[15][15];
string text1, text2;
int lcs(int i, int j) {
  if (i >= text1.length() || j >= text2.length()) {
    return 0;
  }
  if (memo[i][j] != -1) return memo[i][j];
  if (text1[i] == text2[j]) return memo[i][j] = 1 + lcs(i + 1, j + 1);
  return memo[i][j] = lcs(i + 1, j);
}
int longestCommonSubsequence(string t1, string t2) {
  memset(memo, -1, sizeof memo);
  text1 = t1;
  text2 = t2;
  int ans = lcs(0, 0);
  return ans;
}
vector<string> _2p;
void solve() {
  string n;
  cin >> n;
  int ans = 0x3f3f3f3f;
  for (auto x : _2p) {
    int common = longestCommonSubsequence(n, x);
    int rem = x.length() - common;
    int ad = n.length() - common;
    int temp = rem + ad;
    ans = min(ans, temp);
  }
  cout << ans << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  int t;
  cin >> t;
  for (long long i = 1; i <= 1e16;) {
    _2p.push_back(to_string(i));
    i = (i << 1);
  }
  while (t--) {
    solve();
  }
  return 0;
}
