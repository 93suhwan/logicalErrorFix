#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr) cin >> x;
  int height = 1;
  for (int i = 0; i < n; i++) {
    if (i > 0 and !arr[i - 1] and !arr[i]) {
      cout << -1 << '\n';
      return;
    }
    height += arr[i] + (i > 0 and arr[i] and arr[i - 1] ? 4 : 0);
  }
  cout << height << endl;
}
int main(int argc, char const *argv[]) {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
