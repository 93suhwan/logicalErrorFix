#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
void K_K() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  K_K();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<double> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      arr[i] += arr[i - 1];
    }
    double mx = -0x3f3f3f3f3f3f3f3fLL;
    for (int i = 1; i < n; i++) {
      double l = arr[i] / i, r = (arr[n] - arr[i]) / (n - i);
      mx = max({mx, l + r});
    }
    cout << fixed << setprecision(9) << mx << "\n";
  }
}
