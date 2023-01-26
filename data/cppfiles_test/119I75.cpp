#include <bits/stdc++.h>
using namespace std;
int dir_x[] = {-1, 1, 0, 0};
int dir_y[] = {0, 0, -1, 1};
int TC;
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  ;
  cin >> TC;
  for (__typeof(TC + 1) t = 1; t < TC + 1; t++) {
    int n;
    cin >> n;
    int arr[n];
    int minn = 100000000, maxx = -1;
    for (__typeof(n) i = 0; i < n; i++) {
      cin >> arr[i];
      minn = min(minn, arr[i]);
      maxx = max(arr[i], maxx);
    }
    sort(arr, arr + n);
    bool fl = false;
    int ans = 10000000;
    int arr1[n];
    for (__typeof(n) i = 0; i < n; i++) {
      int tmp = 0;
      for (__typeof(n) j = 0; j < n; j++) {
        if (arr[j] <= arr[i])
          tmp += (arr[i] - arr[j]);
        else
          tmp -= (arr[j] - arr[i]);
      }
      if (tmp == 0) {
        ans = 0;
        break;
      }
      if (tmp < 0) tmp *= -1;
      ans = 1;
    }
    cout << ans << endl;
  }
  return 0;
}
