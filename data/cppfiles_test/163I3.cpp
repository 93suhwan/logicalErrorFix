#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    auto solve = [&](long long k) {
      auto b = a;
      vector<long long> c(n + 5);
      for (int i = n; i >= 3; i--) {
        long long val = min(a[i], a[i] - k + c[i + 1] + 2 * c[i + 2]);
        if (val < 0) return false;
        c[i] = val / 3;
      }
      for (int i = 1; i <= 2; i++) {
        if (3 * c[i] > a[i] - k + c[i + 1] + 2 * c[i + 2]) return false;
      }
      return true;
    };
    long long lower = 0, upper = 1e9;
    while (lower < upper) {
      long long mid = (lower + upper + 1) / 2;
      if (solve(mid)) {
        lower = mid;
      } else
        upper = mid - 1;
    }
    cout << lower << "\n";
  }
  return 0;
}
