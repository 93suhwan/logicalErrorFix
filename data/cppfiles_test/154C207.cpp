#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int arr[3];
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  sort(arr, arr + 3);
  if (arr[2] == arr[0] + arr[1]) {
    cout << "YES\n";
    return;
  } else if (arr[0] == arr[1]) {
    if (arr[2] % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  } else if (arr[1] == arr[2]) {
    if (arr[0] % 2 == 0) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
