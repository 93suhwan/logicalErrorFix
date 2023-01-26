#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<long long> max_picks;
    long long a[20];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      max_picks.push_back(pow(10, a[i + 1] - a[i]) - 1);
    }
    max_picks.push_back(1e9 + 10000);
    for (int i = 0; i < n; i++) {
      long long base = pow(10, a[i]);
      long long max_pick = pow(10, a[i] + 1) - 1;
      if (k - max_picks[i] >= 0) {
        k -= max_picks[i];
        ans += base * max_picks[i];
      } else {
        ans += base * (k + 1);
        break;
      }
    }
    cout << ans << '\n';
  }
}
