#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    vector<long long> arr(n, 0);
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long ans = 0;
    long long mine;
    for (long long i = 0; i < n - 1; i++) {
      long long temp = arr[i + 1] - arr[i];
      long long count = ceil(pow(10.0, temp)) - 1;
      if (k < count) {
        mine = k * ceil(pow(10.0, arr[i]));
        ans += mine;
        k = 0;
        break;
      } else {
        mine = count * ceil(pow(10.0, arr[i]));
        ans += mine;
        k -= count;
      }
    }
    mine = k * ceil(pow(10.0, arr[n - 1]));
    ans += mine;
    cout << ans << "\n";
  }
  return 0;
}
