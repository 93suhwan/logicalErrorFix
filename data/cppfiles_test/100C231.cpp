#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (long long i = 0; i <= n - 1; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long ans = arr[0];
    for (long long i = 1; i <= n - 1; i++) {
      ans = max(ans, arr[i] - arr[i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
