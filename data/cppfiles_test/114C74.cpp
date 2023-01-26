#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long k = 1, cnt = n / 2;
  ;
  while (cnt--) {
    cout << arr[k] << " " << arr[0] << endl;
    k++;
  }
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
