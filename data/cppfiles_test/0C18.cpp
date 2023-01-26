#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> vp;
  for (int i = 1; i <= n; i++) {
    string s, s2 = "";
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (j % 2 == 0) {
        s2.push_back(s[j]);
      } else {
        int z = 25 - (s[j] - 'A');
        char c = 'A' + z;
        s2.push_back(c);
      }
    }
    vp.push_back({s2, i});
  }
  sort(vp.begin(), vp.end());
  for (auto e : vp) cout << e.second << " ";
  cout << "\n";
  return 0;
}
