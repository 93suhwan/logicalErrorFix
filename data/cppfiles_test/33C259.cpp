#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n + 1];
  long long pos = 0, mx = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a = arr[i] * arr[i + 1];
    if (a > mx) mx = a;
  }
  cout << mx << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
