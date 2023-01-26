#include <bits/stdc++.h>
using namespace std;
long long lstbt(long long val) {
  long long msk = val & (val - 1);
  return log2(val ^ msk);
}
void c_p_c() {}
int main() {
  c_p_c();
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    std::vector<long long> arr, brr;
    for (long long i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      if (x < 0) {
        arr.push_back(x);
      } else {
        brr.push_back(x);
      }
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end(), greater<long long>());
    long long i = 0, j = 0;
    long long flag = 1;
    long long p = arr.size(), q = brr.size();
    long long ans = 0;
    while (i < p && j < q) {
      if (abs(arr[i]) >= abs(brr[j])) {
        ans += abs(arr[i]) * flag;
        i += k;
      } else {
        ans += abs(brr[j]) * flag;
        j += k;
      }
      flag = 2;
    }
    while (i < p) {
      ans += abs(arr[i]) * flag;
      flag = 2;
      i += k;
    }
    while (j < q) {
      ans += brr[j] * flag;
      flag = 2;
      j += k;
    }
    cout << ans << endl;
  }
}
