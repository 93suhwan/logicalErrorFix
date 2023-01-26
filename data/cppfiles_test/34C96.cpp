#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 500;
int n;
unordered_map<int, int> ans;
vector<int> buc[5050];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, tmp; i <= n; i++) {
    cin >> tmp;
    buc[tmp].push_back(i);
  }
  ans.clear();
  ans[0] = 0;
  for (int i = 0; i <= 5000; i++) {
    if (buc[i].empty()) continue;
    vector<pair<int, int> > newitem;
    newitem.clear();
    for (auto &[x, y] : ans) {
      auto it = upper_bound(buc[i].begin(), buc[i].end(), y);
      if (it == buc[i].end()) continue;
      newitem.push_back({x ^ i, *it});
    }
    for (auto &it : newitem) {
      if (ans.find(it.first) == ans.end()) {
        ans[it.first] = it.second;
      } else {
        ans[it.first] = min(ans[it.first], it.second);
      }
    }
  }
  vector<int> res;
  for (auto &[key, val] : ans) res.push_back(key);
  cout << res.size() << '\n';
  sort(res.begin(), res.end());
  for (auto &it : res) cout << it << " ";
  cout << '\n';
  return 0;
}
