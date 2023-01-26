#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  int m = 0;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> arr[i];
    m = max(m, arr[i]);
  }
  vector<int> as(m + 1, 0);
  bool ass[m + 1][k + 1];
  int tt = n;
  for (int i = 0; i < (int)(n); ++i) {
    if (as[arr[i]] >= k) {
      tt--;
    }
    as[arr[i]]++;
  }
  int to_be_zero = n - tt;
  int max_each_color = tt / k;
  unordered_map<int, vector<int> > mp;
  for (int i = 0; i < (int)(n); ++i) {
    mp[arr[i]].push_back(i);
  }
  int ans[n];
  int color = 0;
  for (auto ele : mp) {
    while (ele.second.size() > k) {
      int ix = ele.second.back();
      ans[ix] = 0;
      ele.second.pop_back();
    }
    for (auto ix : ele.second) {
      ans[ix] = (color++ % k) + 1;
    }
  }
  for (int a : ans) cout << a << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
