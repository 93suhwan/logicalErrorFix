#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solve(string& s) {
  int n, i, l, r;
  n = s.size();
  vector<int> cnt(3);
  for (char c : s) ++cnt[c - '0'];
  if (!cnt[0]) return 0;
  if (!cnt[1]) return 1;
  for (l = 0; l < n; ++l) {
    if (s[l] == '0') break;
  }
  for (r = n - 1; r >= 0; --r) {
    if (s[r] == '0') break;
  }
  cnt[0] = cnt[1] = 0;
  for (i = l; i <= r; ++i) ++cnt[s[i] - '0'];
  if (!cnt[0]) return 0;
  if (!cnt[1]) return 1;
  return 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc, ti = 1;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
  return 0;
}
