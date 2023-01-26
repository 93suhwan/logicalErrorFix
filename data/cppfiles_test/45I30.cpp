#include <bits/stdc++.h>
using namespace std;
int n, t, v;
int arr[100];
void cf() {
  cin >> n;
  v = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] == 0 && arr[i + 1] == 0) {
      cout << -1 << endl;
      v = 1;
    }
  }
  int ans = 1;
  if (v == 0) {
    ans += arr[0];
    for (int i = 1; i < n; ++i) {
      if (arr[i] == 1) {
        ans += arr[i] + 4 * arr[i - 1];
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin >> t;
  for (int z = 0; z < t; ++z) {
    cf();
  }
}
