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
    int sum1 = 0;
    int sum2 = 0;
    int sum11 = 0;
    int sum22 = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      if (i < n / 2)
        sum1 = sum1 + temp;
      else
        sum2 = sum2 + temp;
      if (i <= n / 2)
        sum11 = sum11 + temp;
      else
        sum22 = sum22 + temp;
    }
    for (int i = 0; i < n; i++) {
      if (sum1 != 0 && sum2 != 0) {
        if (i < n / 2) {
          if (abs(sum2) > 0)
            cout << -sum2 << " ";
          else
            cout << "-1 ";
        } else {
          if (abs(sum1) > 0)
            cout << sum1 << " ";
          else
            cout << "1 ";
        }
      } else {
        if (i < n / 2) {
          if (abs(sum22) > 0)
            cout << -sum22 << " ";
          else
            cout << "-1 ";
        } else {
          if (abs(sum11) > 0)
            cout << sum11 << " ";
          else
            cout << "1 ";
        }
      }
    }
    cout << "\n";
  }
}
