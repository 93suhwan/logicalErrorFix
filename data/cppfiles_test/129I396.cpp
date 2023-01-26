#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  unordered_map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a = arr[i];
    int b = (a - 1) / 2;
    mp[1]++;
    mp[b + 1]--;
  }
  int steps = 0;
  int temp = 0;
  for (int i = 1; i <= n; ++i) {
    temp += mp[i];
    if (temp == 0) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (arr[i - 1] != i) {
      steps++;
    }
  }
  cout << steps << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
