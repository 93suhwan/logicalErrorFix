#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  double one = arr.back();
  double two = 0;
  for (int i = 0; i < n - 1; i++) two += arr[i];
  two = two / (n - 1);
  cout << setprecision(7) << one + two << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
