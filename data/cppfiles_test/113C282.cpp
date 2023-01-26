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
    long long ans = 0;
    auto it = lower_bound(a.begin(), a.end(), x);
    long long c = 0;
    long long S1 = S;
    if (it == a.end()) {
      c = x;
      ans += x - a.back();
      S1 += x - a.back();
    } else
      c = *it;
    if (S1 - y < c) {
      ans += c - S1 + y;
    }
    long long ans1 = 0;
    if (it == a.begin()) {
      cout << ans << "\n";
      continue;
    }
    it--;
    ans1 += x - *it;
    S1 = S + ans1;
    ans1 += max(0ll, x - S1 + y);
    cout << min(ans1, ans) << "\n";
  }
}
