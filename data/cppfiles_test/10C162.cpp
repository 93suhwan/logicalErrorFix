#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  vector<int> ans(n, 0);
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    if (mp[v[i]].size() < k) mp[v[i]].push_back(i);
  }
  for (auto ele : mp) {
    if (ele.second.size() == k) {
      int c = 1;
      for (int i = 0; i < ele.second.size(); i++) {
        ans[ele.second[i]] = c;
        c++;
      }
    }
  }
  vector<int> collab;
  for (auto ele : mp) {
    if (ele.second.size() < k) {
      for (int i = 0; i < ele.second.size(); i++)
        collab.push_back(ele.second[i]);
    }
  }
  int c = 1;
  for (int i = 0; i < collab.size() - collab.size() % k; i++) {
    ans[collab[i]] = c;
    if (c == k)
      c = 1;
    else
      c++;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
