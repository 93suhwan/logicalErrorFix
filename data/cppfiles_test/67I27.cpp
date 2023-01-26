#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int N;
double P;
bool check(int m) {
  double x = double(N) * double(N - 1) * double(N - 2) / 6.0;
  double y = double(m) * double(m - 1) * double(N - m) / 2.0 +
             double(m) * double(m - 1) * double(m - 2) / 6.0;
  double p = y / x;
  return p >= P || fabs(P - p) <= eps;
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
