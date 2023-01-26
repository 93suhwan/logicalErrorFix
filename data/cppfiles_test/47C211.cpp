#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, i, j, k;
  cin >> n >> k;
  long long arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  j = 0;
  for (i = 0; i < n && arr[i] < 0; i += k) j += 2 * abs(arr[i]);
  for (i = n - 1; i >= 0 && arr[i] > 0; i -= k) j += 2 * arr[i];
  j -= max(abs(arr[0]), abs(arr[n - 1]));
  return j;
}
int main() {
  long long t;
  cin >> t;
  while (t--) cout << solve() << endl;
  return 0;
}
