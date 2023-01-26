#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 5;
long long pos[30];
void solve() {
  string s;
  string t;
  cin >> s >> t;
  for (long long i = 0; i < s.size(); i++) {
    pos[s[i] - 'a'] = i;
  }
  long long res = 0;
  for (long long i = 0; i < t.size() - 1; i++) {
    res += abs(pos[i] - pos[i + 1]);
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) solve();
}
