#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<long long int>& arr, long long int k, long long int h) {
  long long int damage = 0;
  long long int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    damage += min(arr[i + 1] - arr[i], k);
  }
  damage += k;
  return damage >= h;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, h;
    cin >> n >> h;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int l = 1, r = h, ans;
    while (l <= r) {
      long long int mid = l + (r - l) / 2;
      if (isValid(arr, mid, h))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
