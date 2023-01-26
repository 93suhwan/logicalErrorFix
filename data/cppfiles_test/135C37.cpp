#include <bits/stdc++.h>
using namespace std;
long long f() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long sol = 0;
  for (int i = 0; i < n - 2 * k; i++) {
    sol += a[i];
  }
  for (int i = n - 2 * k; i < n - k; i++) {
    if (a[i] == a[i + k]) sol += 1;
  }
  return sol;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cout << f() << '\n';
  }
  return 0;
}
