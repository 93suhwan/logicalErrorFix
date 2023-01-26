#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
char s[maxn];
int v[maxn];
unordered_map<int, vector<int>> pos;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m >> s + 1;
    pos.clear();
    for (int i = 1; i <= n; ++i) {
      v[i] = v[i - 1] + (i % 2 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
      pos[v[i] + v[i - 1]].push_back(i);
    }
    for (int tt = 1; tt <= m; ++tt) {
      int lf, rt;
      cin >> lf >> rt;
      if (v[rt] == v[lf - 1]) {
        cout << "0\n";
        continue;
      } else if ((rt - lf + 1) & 1)
        cout << "1\n";
      else
        cout << "2\n" << lf++ << endl;
      int vv = v[rt] + v[lf - 1];
      auto& it = pos[vv];
      cout << (*lower_bound(it.begin(), it.end(), lf)) << endl;
    }
  }
  return 0;
}
