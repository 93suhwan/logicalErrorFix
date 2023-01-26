#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    long long ans = 0, digit = 0, li = 0, lpow = 0;
    while (k > 0) {
      if (arr[li] == digit) {
        li++;
        lpow = 0;
      } else {
        lpow++;
      }
      if (li >= n or
          pow(10, arr[min(n - 1, li + 1)] - arr[min(n - 2, li)]) - 1 > k) {
        k++;
        k *= pow(10, digit);
        ans += k;
        k = 0;
        break;
      }
      ans += 9 * pow(10, digit);
      k -= 9 * pow(10, lpow);
      digit++;
    }
    cout << ans << "\n";
  }
}
