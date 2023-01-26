#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  long long m;
  vector<long long> arr(3);
  cin >> arr[0] >> arr[1] >> arr[2] >> m;
  long long total_pairs = arr[0] + arr[1] + arr[2] - 3;
  long long min_pairs = arr[2] - arr[1] - arr[0] - 1;
  if (m >= min_pairs && m <= total_pairs) {
    cout << "YES"
         << "\n";
  } else
    cout << "NO"
         << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
}
