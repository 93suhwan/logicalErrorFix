#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> um;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    um[t].push_back(i);
  }
  vector<int> ans(n, 0);
  vector<int> left_over;
  for (auto x : um) {
    vector<int> temp = x.second;
    for (int i = 0; i < min(k, (int)temp.size()); i++) {
      left_over.push_back(temp[i]);
    }
  }
  int cnt = 1;
  int groups = left_over.size() / k;
  int x = 0;
  int start = 0;
  while (x < groups) {
    ans[left_over[start]] = cnt;
    start++;
    cnt++;
    if (cnt > k) {
      cnt = 1;
      x++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
