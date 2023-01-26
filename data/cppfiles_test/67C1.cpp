#include <bits/stdc++.h>
using namespace std;
double prob(int n, int k) {
  double ans = 1.0 * k * (k - 1) * (k - 2) / 6 +
               1.0 * k * (k - 1) / 2 * (n - k) +
               0.5 * k * (n - k) * (n - k - 1) / 2;
  ans /= 1.0 * n * (n - 1) * (n - 2) / 6;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  double p;
  cin >> p;
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (prob(n, mid) >= p)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << "\n";
  return 0;
}
