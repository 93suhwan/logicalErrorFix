#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> A, B;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    A[a[i]]++;
    B[b[i]]++;
  }
  long long ans = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    ans -= (long long)(A[a[i]] - 1) * (B[b[i]] - 1);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
