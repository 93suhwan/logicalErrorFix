#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 109, inf = 1e9;
const long double pi = acos(-1), eps = 1e-9;
int n, k;
int x[N], y[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  long double ans = 1e18, bst;
  for (long double theta = 0; theta <= 2 * pi; theta += 0.01) {
    vector<long double> R;
    for (int i = 1; i <= n; i++) {
      long double v = x[i] * cos(theta) + y[i] * sin(theta);
      if (v < 1e-9) continue;
      R.push_back({(x[i] * x[i] + y[i] * y[i]) / (2 * v)});
    }
    sort(R.begin(), R.end());
    if (R.size() >= k && R[k - 1] < ans) {
      ans = min(ans, R[k - 1]);
      bst = theta;
    }
  }
  for (long double theta = bst - 0.01; theta <= bst + 0.01; theta += 0.0001) {
    vector<long double> R;
    for (int i = 1; i <= n; i++) {
      long double v = x[i] * cos(theta) + y[i] * sin(theta);
      if (v < 1e-9) continue;
      R.push_back({(x[i] * x[i] + y[i] * y[i]) / (2 * v)});
    }
    sort(R.begin(), R.end());
    if (R.size() >= k && R[k - 1] < ans) {
      ans = min(ans, R[k - 1]);
      bst = theta;
    }
  }
  for (long double theta = bst - 0.00001; theta <= bst + 0.00001;
       theta += 0.000001) {
    vector<long double> R;
    for (int i = 1; i <= n; i++) {
      long double v = x[i] * cos(theta) + y[i] * sin(theta);
      if (v < 1e-9) continue;
      R.push_back({(x[i] * x[i] + y[i] * y[i]) / (2 * v)});
    }
    sort(R.begin(), R.end());
    if (R.size() >= k && R[k - 1] < ans) {
      ans = min(ans, R[k - 1]);
      bst = theta;
    }
  }
  for (long double theta = bst - 0.0000001; theta <= bst + 0.0000001;
       theta += 0.00000001) {
    vector<long double> R;
    for (int i = 1; i <= n; i++) {
      long double v = x[i] * cos(theta) + y[i] * sin(theta);
      if (v < 1e-9) continue;
      R.push_back({(x[i] * x[i] + y[i] * y[i]) / (2 * v)});
    }
    sort(R.begin(), R.end());
    if (R.size() >= k && R[k - 1] < ans) {
      ans = min(ans, R[k - 1]);
      bst = theta;
    }
  }
  if (ans > 1e16) return cout << -1, 0;
  cout << fixed << ans;
}
