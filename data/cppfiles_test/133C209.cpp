#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> bg(n - 2);
  for (int i = 0; i < n - 2; ++i) {
    cin >> bg[i];
  }
  int idx = -1;
  for (int i = 1; i < bg.size(); ++i) {
    if (bg[i - 1][1] != bg[i][0]) {
      idx = i;
      break;
    }
  }
  string res = "";
  for (int i = 0; i < bg.size(); ++i) {
    if (i == bg.size() - 1) {
      res += bg[i];
    } else {
      res += bg[i][0];
    }
  }
  if (idx == -1) {
    res += 'a';
  } else {
    res.insert(idx, bg[idx - 1].substr(1, 1));
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
