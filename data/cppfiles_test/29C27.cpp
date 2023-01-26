#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, tmp;
    long long arr[5];
    long long ans;
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      if (tmp <= 1) {
        arr[tmp]++;
      }
    }
    if (arr[0] == 0) {
      arr[0]++;
    } else {
      arr[0] = pow(2, arr[0]);
    }
    ans = arr[1] * arr[0];
    cout << ans << endl;
  }
}
