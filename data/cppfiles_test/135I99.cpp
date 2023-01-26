#include <bits/stdc++.h>
using namespace std;
template <class T>
T solve(T n, T k) {
  vector<T> arr(n);
  T sum = 0;
  for (T i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr.begin(), arr.end());
  T i = n - 1;
  while (k > 0) {
    sum -= (arr[i] + arr[i - 2]);
    sum += (arr[i - 2] / arr[i]);
    i--;
    k--;
  }
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
  }
  return 0;
}
