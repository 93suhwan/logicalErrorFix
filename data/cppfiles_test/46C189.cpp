#include <bits/stdc++.h>
using namespace std;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 998244353;
const long long INF = 1e17;
void print(vector<long long>& arr) {
  for (long long i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << "\n";
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long ans = 0;
  long long maxi = arr[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    if (arr[i] > maxi) {
      maxi = arr[i];
      ans++;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
