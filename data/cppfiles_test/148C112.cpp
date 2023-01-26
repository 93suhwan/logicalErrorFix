#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long w, h, k, arr[4], brr[1000000], ans;
    cin >> w >> h;
    for (int i = 0; i < 4; i++) {
      cin >> k;
      for (int j = 0; j < k; j++) {
        cin >> brr[j];
      }
      arr[i] = (brr[k - 1] - brr[0]);
    }
    arr[0] = max(arr[0], arr[1]);
    arr[2] = max(arr[2], arr[3]);
    ans = max(arr[0] * h, arr[2] * w);
    cout << ans << endl;
  }
}
