#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<int> arr(3);
  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr.begin(), arr.end());
  if (arr[0] + arr[1] == arr[2]) {
    cout << "YES" << endl;
    return;
  } else {
    if (arr[0] == arr[1] && arr[2] % 2 == 0) {
      cout << "YES" << endl;
      return;
    } else if (arr[1] == arr[2] && arr[0] % 2 == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
