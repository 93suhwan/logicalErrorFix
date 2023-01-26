#include <bits/stdc++.h>
using namespace std;
bool isDigit(char ch) {
  if (ch >= '0' and ch <= '9') return true;
  return false;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int mx = -1;
  for (long long int i = 0; i < n - 1; i++) {
    mx = max(mx, arr[i] * arr[i + 1]);
  }
  cout << mx << endl;
}
int32_t main() {
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
