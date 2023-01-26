#include <bits/stdc++.h>
using namespace std;
inline void task() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long maxInd = max_element(arr.begin(), arr.end()) - arr.begin();
  if (maxInd + 1 == n)
    cout << arr[maxInd] * arr[maxInd - 1] << endl;
  else if (maxInd == 0)
    cout << arr[0] * arr[1] << endl;
  else if (arr[maxInd - 1] > arr[maxInd + 1])
    cout << arr[maxInd - 1] * arr[maxInd] << endl;
  else if (arr[maxInd - 1] <= arr[maxInd + 1])
    cout << arr[maxInd + 1] * arr[maxInd] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long size;
  cin >> size;
  while (size--) task();
}
