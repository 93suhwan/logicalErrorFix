#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int mp[maxn];
vector<int> pos[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < maxn; i++) mp[i] = i;
  int n = 0;
  int Q;
  cin >> Q;
  while (Q--) {
    int t, x, y;
    cin >> t >> x;
    if (t == 1) {
      pos[mp[x]].push_back(++n);
      continue;
    }
    cin >> y;
    if (x == y) continue;
    if (pos[mp[x]].size() > pos[mp[y]].size()) {
      swap(mp[x], mp[y]);
    }
    for (int i : pos[mp[x]]) pos[mp[y]].push_back(i);
    pos[mp[x]].clear();
    pos[mp[x]].shrink_to_fit();
  }
  vector<int> ans(n);
  for (int i = 1; i < maxn; i++)
    for (int j : pos[mp[i]]) ans[j - 1] = i;
  for (int i : ans) cout << i << ' ';
  cout << endl;
  return 0;
}
