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
  int steps = 0;
  for (int i = 1; i <= n; ++i) {
    int a = arr[i - 1];
    if (a == i) {
      continue;
    } else if ((a / 2) < i) {
      cout << -1 << endl;
      return;
    } else {
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
