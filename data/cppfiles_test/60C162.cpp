#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  long long arr[n];
  map<long long, long long> cnt;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
    sum += arr[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if ((2 * sum) % n == 0) {
      long long p = (2 * sum) / n - arr[i];
      if (cnt.count(p)) {
        ans += cnt[p];
      }
      if (arr[i] == p) {
        ans--;
      }
    }
  }
  cout << ans / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
