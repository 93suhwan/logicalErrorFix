#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int sum = *max_element(arr.begin(), arr.end());
  int cnt = 1000000000;
  for (int i = 0; i < n; i++) {
    if (arr[i] != sum) cnt = min(arr[i] & sum, cnt);
  }
  cout << cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
