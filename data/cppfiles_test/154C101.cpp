#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    if (c % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (a == c) {
    if (b % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (b == c) {
    if (a % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    int arr[3];
    arr[0] = a, arr[1] = b, arr[2] = c;
    sort(arr, arr + 3);
    if (arr[2] - arr[1] == arr[0])
      cout << "YES\n";
    else if (arr[2] - arr[0] == arr[1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
