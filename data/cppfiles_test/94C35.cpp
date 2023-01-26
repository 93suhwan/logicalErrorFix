#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n, 0);
    for (long long i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      arr[i] = pow(10, x);
    }
    long long sum = 0;
    k += 1;
    for (long long i = 0; i < n && k != 0; ++i) {
      if (i != n - 1) {
        long long occ = min(k, arr[i + 1] / arr[i] - 1);
        sum += arr[i] * occ;
        k -= occ;
      } else {
        sum += k * arr[i];
        k = 0;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
