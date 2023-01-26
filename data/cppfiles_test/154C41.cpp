#include <bits/stdc++.h>
using namespace std;
long long int t, arr[102];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] == arr[1]) {
      if (arr[2] % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (arr[1] == arr[2]) {
      if (arr[0] % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (arr[0] == arr[1] && arr[1] == arr[2]) {
      if (arr[1] % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (arr[0] + arr[1] == arr[2]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
