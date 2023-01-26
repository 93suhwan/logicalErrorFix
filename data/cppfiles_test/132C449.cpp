#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  n = 7;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << arr[0] << " " << arr[1] << " ";
  if (arr[0] + arr[1] == arr[2])
    cout << arr[3] << '\n';
  else
    cout << arr[2] << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
