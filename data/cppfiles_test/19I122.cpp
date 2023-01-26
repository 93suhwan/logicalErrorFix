#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    if (arr[0] == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n == 2) {
    if (arr[0] == 0 || arr[1] == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n == 3) {
    if (abs(arr[0] - arr[1]) == abs(arr[2]) ||
        abs(arr[0] + arr[1]) == abs(arr[2]))
      cout << "YES\n";
    else if (abs(arr[1] - arr[2]) == abs(arr[0]) ||
             abs(arr[1] + arr[2]) == abs(arr[0]))
      cout << "YES\n";
    else if (abs(arr[2] - arr[0]) == abs(arr[1]) ||
             abs(arr[2] + arr[0]) == abs(arr[1]))
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return 0;
}
