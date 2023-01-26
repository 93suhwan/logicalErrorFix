#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  vector<int> idx(n);
  int arr[n][5];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 5; ++j) cin >> arr[i][j];
  if (n == 1) return 1;
  for (int i = 0; i < 5; ++i) {
    int pos = 0, mx = INT_MAX;
    for (int j = 0; j < n; ++j) {
      if (arr[j][i] < mx) {
        pos = j;
        mx = arr[j][i];
      }
    }
    idx[pos]++;
  }
  vector<int> ans(idx);
  sort(idx.begin(), idx.end());
  if (idx[n - 1] == idx[n - 2]) return -1;
  return max_element(ans.begin(), ans.end()) - ans.begin() + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test = 1;
  cin >> test;
  while (test--) cout << solve() << "\n";
}
