#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    int srt[n];
    for (int i = 0; i < n; i++) srt[i] = arr[i];
    sort(srt, srt + n);
    int prev_index = -2;
    for (int i = 0; i < n; i++) {
      int s = 0, e = n - 1;
      int target = arr[i];
      while (s <= e) {
        int mid = (s + e) / 2;
        if (srt[mid] == target) {
          if (mid - prev_index == 1) {
            prev_index = mid;
            break;
          }
          if (i == 0) {
            prev_index = mid;
            cnt++;
            break;
          }
          cnt++;
          prev_index = mid;
          break;
        } else if (srt[mid] < target)
          s = mid + 1;
        else
          e = mid - 1;
      }
    }
    if (k >= cnt)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
