#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    long long m = (long long)n * (long long)(n + 1) / 2;
    if (sum % m == 0) {
      long long ans = 0;
      sum /= m;
      bool test = true;
      ans = (arr[n - 1] - arr[0] + sum);
      if (ans % n != 0 || ans <= 0) {
        test = false;
      }
      for (int i = 1; i < n; i++) {
        ans = (arr[i - 1] - arr[i] + sum);
        if (ans % n != 0 || ans <= 0) {
          test = false;
          break;
        }
      }
      if (!test) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        ans = (arr[n - 1] - arr[0] + sum) / n;
        cout << ans << " ";
        for (int i = 1; i < n; i++) {
          ans = (arr[i - 1] - arr[i] + sum) / n;
          cout << ans << " ";
        }
        cout << "\n";
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
