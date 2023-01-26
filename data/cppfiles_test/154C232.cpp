#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 1e6;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, b, c;
  cin >> a >> b >> c;
  long long arr[3] = {a, b, c};
  sort(arr, arr + 3);
  long long ans = 0;
  if (arr[2] == arr[0] + arr[1]) {
    ans = 1;
  } else {
    if (arr[0] % 2 == 0 && arr[1] == arr[2] ||
        arr[2] % 2 == 0 && arr[0] == arr[1]) {
      ans = 1;
    }
  }
  if (ans == 0) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
