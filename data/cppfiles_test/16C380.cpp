#include <bits/stdc++.h>
using namespace std;
int fx[8][2] = {{-1, 1}, {-1, 0}, {-1, -1}, {1, 1},
                {1, -1}, {1, 0},  {0, 1},   {0, -1}};
const int mod = 199999;
const int M = 300500;
const int inf = 1e9 + 1e9;
const long long llinf = 1e18 + 1e7;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  sort(s.begin(), s.end());
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
