#include <bits/stdc++.h>
using namespace std;
int const p = 31;
long long const MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  long long S = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    S += a[i];
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long ans = max({0ll, x + y - S});
    if (ans + a.back() < x) {
      ans = x - a.back();
    }
    cout << ans << "\n";
  }
}
