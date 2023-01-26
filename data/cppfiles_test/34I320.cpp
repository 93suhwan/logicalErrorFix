#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long mn = INT_MAX, mni = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= mn) {
      mn = a[i];
      mni = i;
    }
  }
  long long mx = INT_MIN;
  for (int i = 1; i < n; i++) {
    if (mni != i) {
      long long val = a[mni] | a[i];
      mx = max(mx, i * mni - k * val);
    }
    long long val = a[i] | a[n];
    mx = max(mx, i * n - k * val);
  }
  if (mni != n) {
    long long val = a[mni] | a[n];
    mx = max(mx, n * mni - k * val);
  }
  cout << mx << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
