#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n + 1];
  long long pos = 0, mx = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    if (mx < arr[i]) mx = arr[i], pos = i;
  }
  long long a = arr[pos], b = arr[pos];
  if (pos > 0) a = a * arr[pos - 1];
  if (pos < n - 1) b = b * arr[pos + 1];
  cout << max(a, b) << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
