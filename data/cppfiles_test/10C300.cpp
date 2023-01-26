#include <bits/stdc++.h>
using namespace std;
void help() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (mp[x].size() < k) mp[x].push_back(i);
  }
  vector<int> ans(n, 0);
  int m = 0;
  for (auto i : mp) {
    m += i.second.size();
  }
  m -= m % k;
  int c = 0;
  for (auto i : mp) {
    for (auto p : i.second) {
      c++;
      ans[p] = c;
      c = c % k;
      m--;
      if (m == 0) {
        for (int k = 0; k < n; k++) cout << ans[k] << " ";
        cout << endl;
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    help();
  }
  return 0;
}
