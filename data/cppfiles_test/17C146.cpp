#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, ans = 0;
  cin >> n;
  vector<int> idx(n);
  int arr[n][5];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) cin >> arr[i][j];
  }
  for (int i = 1; i < n; ++i) {
    int cnt2 = 0;
    for (int k = 0; k < 5; ++k) {
      if (arr[ans][k] < arr[i][k]) ++cnt2;
    }
    if (cnt2 < 3) ans = i;
  }
  for (int i = 0; i < n; ++i) {
    if (i == ans) continue;
    int cnt2 = 0;
    for (int k = 0; k < 5; ++k) {
      if (arr[ans][k] < arr[i][k]) ++cnt2;
    }
    if (cnt2 < 3) return -1;
  }
  return ans + 1;
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
