#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int &a : A) {
    cin >> a;
  }
  sort(A.begin(), A.end());
  long long ans = 0;
  for (int i = 0; i < n - 2 * k; i++) {
    ans += 1ll * A[i];
  }
  int mx = 0;
  vector<int> F(200001);
  for (int i = n - 2 * k; i < n; i++) {
    F[A[i]]++;
    mx = max(mx, F[A[i]]);
  }
  if (mx >= k) {
    ans += mx - k;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
