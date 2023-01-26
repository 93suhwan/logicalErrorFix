#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<vector<int>> v;
  map<int, int> idx;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    idx[arr[i]] = i;
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    v.push_back({s[i] - '0', arr[i]});
  }
  sort(v.begin(), v.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[idx[v[i][1]]] = i + 1;
  }
  for (int i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
