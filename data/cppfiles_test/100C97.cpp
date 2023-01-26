#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, maxi = INT_MIN, sum = 0;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) return arr[0];
  sort(arr, arr + n);
  for (long long i = 0; i < n; i++) {
    maxi = max(maxi, arr[i] - sum);
    sum = arr[i];
  }
  return maxi;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
