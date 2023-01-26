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
    int sum1 = 0;
    int sum2 = 0;
    int sumn = 0;
    int sump = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      arr[i] = temp;
      if (i < n / 2)
        sum1 = sum1 + temp;
      else
        sum2 = sum2 + temp;
      if (temp < 0)
        sumn = sumn + temp;
      else
        sump = sump + temp;
    }
    if (sum1 != 0 && sum2 != 0) {
      for (int i = 0; i < n; i++) {
        if (i < n / 2)
          cout << -sum2 << " ";
        else
          cout << sum1 << " ";
      }
      cout << "\n";
    } else {
      for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
          cout << sumn << " ";
        else
          cout << -sump << " ";
      }
      cout << "\n";
    }
  }
}
