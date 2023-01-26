#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 109, inf = 1e9;
const double pi = acos(-1), eps = 1e-9;
int n, k;
int x[N], y[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] == 0 && y[i] == 0) {
      k--;
    }
  }
  if (k <= 0) return cout << 0, 0;
  double ans = 1e9, bst;
  for (double theta = 0; theta <= 2 * pi; theta += 0.01) {
    vector<double> R;
    for (int i = 1; i <= n; i++) {
      double v = x[i] * cos(theta) + y[i] * sin(theta);
      if (v < 1e-6) continue;
      R.push_back({(1ll * x[i] * x[i] + 1ll * y[i] * y[i]) / (2 * v)});
    }
    sort(R.begin(), R.end());
    if (R.size() >= k && R[k - 1] < ans) {
      ans = min(ans, R[k - 1]);
      bst = theta;
    }
  }
  double low = bst - 0.01, high = bst + 0.01;
  while (high - low > 1e-7) {
    double m1 = low + (high - low) / 3;
    double m2 = high - (high - low) / 3;
    double ans1 = 1e12, ans2 = 1e12;
    {
      vector<double> R;
      for (int i = 1; i <= n; i++) {
        double v = x[i] * cos(m1) + y[i] * sin(m1);
        if (v < 1e-6) continue;
        R.push_back({(1ll * x[i] * x[i] + 1ll * y[i] * y[i]) / (2 * v)});
      }
      sort(R.begin(), R.end());
      if (R.size() >= k) ans1 = R[k - 1];
    }
    {
      vector<double> R;
      for (int i = 1; i <= n; i++) {
        double v = x[i] * cos(m2) + y[i] * sin(m2);
        if (v < 1e-6) continue;
        R.push_back({(1ll * x[i] * x[i] + 1ll * y[i] * y[i]) / (2 * v)});
      }
      sort(R.begin(), R.end());
      if (R.size() >= k) ans2 = R[k - 1];
    }
    if (ans1 < ans2) {
      high = m2;
      ans = ans1;
    } else {
      low = m1;
      ans = ans2;
    }
  }
  cout << fixed << ans;
}
