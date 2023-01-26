#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 1;
const long long mod = 1e9 + 7;
void solve() {
  string s, word;
  int ans = 0;
  cin >> s >> word;
  for (int i = 1; i < word.size(); i++)
    ans +=
        s.find(max(word[i], word[i - 1])) - s.find(min(word[i], word[i - 1]));
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  for (int I = 1; I <= t; I++) {
    solve();
  }
  return 0;
}
