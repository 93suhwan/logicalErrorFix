#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long k;
  cin >> k;
  vector<long long> x(k);
  for (long long i = 0; i < k; i++) cin >> x[i];
  cin >> k;
  vector<long long> x1(k);
  for (long long i = 0; i < k; i++) cin >> x1[i];
  cin >> k;
  vector<long long> y(k);
  for (long long i = 0; i < k; i++) cin >> y[i];
  cin >> k;
  vector<long long> y1(k);
  for (long long i = 0; i < k; i++) cin >> y1[i];
  cout << max({(y.back() - y.front()) * w, (x.back() - x.front()) * h,
               (y1.back() - y1.front()) * w, (x1.back() - x1.front()) * h});
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TestCases = 1;
  cin >> TestCases;
  while (TestCases--) {
    solve();
    cout << "\n";
  }
}
