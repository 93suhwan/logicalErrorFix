#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int q, ans[N];
map<int, vector<int> > pos;
int main() {
  cin >> q;
  int idx = 0;
  for (int qq = 0; qq < q; qq++) {
    int t;
    cin >> t;
    int x, y;
    if (t == 1) {
      cin >> x;
      pos[x].push_back(idx);
      idx++;
    } else {
      cin >> x >> y;
      if (x == y) continue;
      if (pos[x].size() > pos[y].size()) pos[x].swap(pos[y]);
      for (int& i : pos[x]) pos[y].push_back(i);
      pos[x].clear();
    }
  }
  memset(ans, -1, sizeof ans);
  for (const auto& p : pos) {
    for (int i : p.second) ans[i] = p.first;
  }
  for (int i = 0; i < N; i++) {
    if (ans[i] != -1) cout << ans[i] << " ";
  }
  return 0;
}
