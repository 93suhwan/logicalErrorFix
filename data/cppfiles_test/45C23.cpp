#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int height = 1;
  bool flag = true;
  if (arr[0] == 1) height += 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == 0 && arr[i - 1] == 0) {
      flag = false;
    }
    if (arr[i] == 1 && arr[i - 1] == 0) height += 1;
    if (arr[i] == 1 && arr[i - 1] == 1) height += 5;
  }
  if (flag)
    cout << height << endl;
  else
    cout << -1 << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
