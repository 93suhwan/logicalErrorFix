#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i;
  cin >> n;
  long long int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (n % 2 == 0) {
    long long int i;
    for (i = n - 1; i >= n / 2; i--) cout << arr[i] << " " << arr[0] << endl;
    return;
  }
  for (i = n - 1; i > n / 2; i--) {
    cout << arr[i] << " " << arr[0] << endl;
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
