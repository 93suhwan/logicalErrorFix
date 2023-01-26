#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int w, h;
  cin >> w >> h;
  long long int k1;
  cin >> k1;
  vector<long long int> x1(k1, 0);
  for (long long int i = (0); i < (k1); ('+' == '-') ? i-- : i++) cin >> x1[i];
  long long int k2;
  cin >> k2;
  vector<long long int> x2(k2, 0);
  for (long long int i = (0); i < (k2); ('+' == '-') ? i-- : i++) cin >> x2[i];
  long long int k3;
  cin >> k3;
  vector<long long int> y1(k3, 0);
  for (long long int i = (0); i < (k3); ('+' == '-') ? i-- : i++) cin >> y1[i];
  long long int k4;
  cin >> k4;
  vector<long long int> y2(k4, 0);
  for (long long int i = (0); i < (k4); ('+' == '-') ? i-- : i++) cin >> y2[i];
  long long int max1 = (x1[k1 - 1] - x1[0]) * h,
                max2 = (x2[k2 - 1] - x2[0]) * h,
                max3 = (y1[k3 - 1] - y1[0]) * w,
                max4 = (y2[k4 - 1] - y2[0]) * w;
  long long int ans = max(max(max1, max2), max(max3, max4));
  cout << ans << " ";
  cout << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
