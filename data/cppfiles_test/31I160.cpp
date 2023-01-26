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
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      if (i < n / 2)
        sum1 = sum1 + temp;
      else
        sum2 = sum2 + temp;
    }
    for (int i = 0; i < n; i++) {
      if (i < n / 2)
        cout << -sum2 << " ";
      else
        cout << sum1 << " ";
    }
    cout << "\n";
  }
}
