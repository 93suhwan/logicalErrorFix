#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<bool>> v;
bool found;
vector<int> ans, curr;
void solve(int step, int id, bool flag) {
  int i, j, k;
  if (step == 5) {
    found = true;
    ans = curr;
  } else {
    if (found) return;
    for (i = id; i <= n; i++) {
      bool valid = true;
      for (auto p : curr) {
        if (v[p][i] != flag) {
          valid = false;
          break;
        }
      }
      if (valid) {
        curr.push_back(i);
        solve(step + 1, i + 1, flag);
        curr.pop_back();
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, a, b, i, j, k;
  cin >> n >> m;
  if (n > 48) n = 48;
  v.assign(n + 1, vector<bool>(n + 1, false));
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    if ((a <= n) && (b <= n)) {
      v[a][b] = true;
      v[b][a] = true;
    }
  }
  found = false;
  solve(0, 1, true);
  if (!found) {
    solve(0, 1, false);
  }
  if (!found)
    cout << "-1\n";
  else {
    for (auto p : ans) cout << p << " ";
    cout << "\n";
  }
  return 0;
}
