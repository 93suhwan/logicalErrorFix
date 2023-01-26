#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> vi(n);
    for (int i = 0; i < n; i++) {
      cin >> vi[i];
    }
    long long mx = 2 * 10e-5;
    if (n == 1) {
      mx = vi[0];
    } else if (n == 2) {
      mx = max(vi[0], abs(vi[1] - vi[0]));
    } else {
      sort(vi.begin(), vi.end());
      for (int j = 1; j < n; j++) {
        mx = max(mx, abs(vi[j] - vi[j - 1]));
      }
    }
    cout << mx << "\n";
  }
  return 0;
}
