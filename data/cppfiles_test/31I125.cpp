#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int ans = INT_MAX;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      for (int i = 0; i < n; i++) {
        if (i < n / 2)
          cout << -arr[n - 1 - i] << " ";
        else
          cout << arr[n - 1 - i] << " ";
      }
      cout << "\n";
    } else {
      int a = arr[0];
      int b = arr[1];
      int c = arr[2];
      if (a + b != 0)
        cout << c << " " << c << " " << -(a + b) << " ";
      else
        cout << b << " " << -(a + c) << " " << b << " ";
      for (int i = 3; i < n; i++) {
        if (i - 3 < (n - 3) / 2)
          cout << -arr[n - 1 - i + 3] << " ";
        else
          cout << arr[n - 1 - i + 3] << " ";
      }
      cout << "\n";
    }
  }
}
