#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int MAXN = 1e9 + 7;
const int inf = 1e9;
void solve() {
  string s;
  cin >> s;
  int red = 0;
  int green = 0;
  vector<int> occ(40, 0);
  for (auto x : s) {
    occ[x - 'a']++;
  }
  for (int i = 0; i < 30; i++) {
    if (!occ[i]) continue;
    if (occ[i] >= 2) red++, green++;
    if (occ[i] == 1) {
      if (red < green) {
        red++;
      } else if (red == green) {
        red++;
      } else {
        green++;
      }
    }
  }
  cout << min(red, green) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
