#include <bits/stdc++.h>
using namespace std;
inline void task() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long max = arr[0] * arr[1];
  for (long long i = 0; i < n - 1; i++)
    if (arr[i] * arr[i + 1] > max) max = arr[i] * arr[i + 1];
  cout << max << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long size;
  cin >> size;
  while (size--) task();
}
