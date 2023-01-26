#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<int> v(32, 0);
  for (int i = 0; i < n; ++i) {
    int a = arr[i];
    for (int j = 0; j < 32; ++j) {
      if ((a & (1 << j)) != 0) {
        v[j]++;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 0; j < 32; ++j) {
      if (v[j] % i == 0) {
      } else {
        flag = 0;
      }
    }
    if (flag == 1) {
      ans.push_back(i);
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
