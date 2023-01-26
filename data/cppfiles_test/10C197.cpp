#include <bits/stdc++.h>
using namespace std;
void solve() {
  map<int, vector<int>> mp;
  int n, k;
  cin >> n >> k;
  vector<int> res(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x].push_back(i);
  }
  vector<int> tmp;
  for (auto it : mp) {
    while (it.second.size() > k) it.second.pop_back();
    for (auto &j : it.second) tmp.push_back(j);
  }
  while (tmp.size() % k != 0) tmp.pop_back();
  int cnt = 0;
  for (int i = 0; i < tmp.size(); i++) {
    res[tmp[i]] = cnt + 1;
    cnt = (cnt + 1) % k;
  }
  for (int i = 0; i < n; i++) cout << res[i] << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
