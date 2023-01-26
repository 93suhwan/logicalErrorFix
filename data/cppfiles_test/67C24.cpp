#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int N;
double P;
bool check(int m) {
  double x = double(N * (N - 1) * (N - 2)) / 6.0;
  double y = double(m * (m - 1) * (m - 2) / 6) +
             double(m * (m - 1) * (N - m) / 2) +
             double(m * (N - m) * (N - m - 1) / 2) * 0.5;
  double p = y / x;
  return (p >= P || fabs(P - p) <= eps);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> P;
  int l = 0, r = N;
  int ans = l;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
