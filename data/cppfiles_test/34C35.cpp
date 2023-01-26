#include <bits/stdc++.h>
using namespace std;
const int MAXV = 5001, MAXXOR = (1 << 13);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> A(n + 1);
  vector<int> values;
  values.reserve(MAXV);
  vector<vector<int>> pos(MAXV);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    if (pos[A[i]].empty()) values.push_back(A[i]);
    pos[A[i]].push_back(i);
  }
  sort(values.begin(), values.end());
  vector<int> smallest_idx(MAXXOR, n + 1);
  smallest_idx[0] = 0;
  for (const int &x : values) {
    for (int cur = 0; cur < MAXXOR; ++cur) {
      int id = smallest_idx[cur ^ x];
      auto new_id = upper_bound(pos[x].begin(), pos[x].end(), id);
      if (new_id != pos[x].end()) {
        smallest_idx[cur] = min(smallest_idx[cur], *new_id);
      }
    }
  }
  vector<int> res;
  res.reserve(MAXXOR);
  for (int i = 0; i < MAXXOR; ++i)
    if (smallest_idx[i] != n + 1) res.push_back(i);
  cout << res.size() << '\n';
  for (const int &x : res) cout << x << ' ';
  return 0;
}
