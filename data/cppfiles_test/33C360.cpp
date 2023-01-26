#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  c_p_c();
  int t;
  cin >> t;
  while (t--) {
    long long n, arr[100005];
    cin >> n;
    for (long long i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    long long ans = INT_MIN;
    for (long long i = 0; i < n - 1; ++i) {
      if (i == 0) {
        ans = max(ans, arr[i] * arr[i + 1]);
      } else {
        ans = max(ans, max(arr[i] * arr[i - 1], arr[i] * arr[i + 1]));
      }
    }
    cout << ans << endl;
  }
}
