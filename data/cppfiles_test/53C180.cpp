#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long temp[n], arr[n], sum = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    arr[i] = x;
    temp[i] = x;
  }
  sort(arr, arr + n);
  long long i = 0, count = 0;
  while (i < n) {
    long long ind = lower_bound(arr, arr + n, temp[i]) - arr;
    if (ind == n - 1) {
      i++;
      count++;
      continue;
    }
    i++;
    long long j = ind + 1;
    while (j < n && temp[i] == arr[j]) {
      j++;
      i++;
    }
    count++;
  }
  if (count <= k) {
    cout << "Yes"
         << "\n";
    return;
  }
  cout << "No"
       << "\n";
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
