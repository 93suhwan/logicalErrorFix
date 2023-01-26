#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int h = 1;
  bool prev1 = false, prev0 = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      prev1 = false;
      if (prev0) {
        cout << -1 << endl;
        return;
      } else
        prev0 = true;
    } else {
      prev0 = false;
      if (prev1) {
        h += 5;
      } else {
        prev1 = true;
        h += 1;
      }
    }
  }
  cout << h << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
