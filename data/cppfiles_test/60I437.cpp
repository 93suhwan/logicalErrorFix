#include <bits/stdc++.h>
using namespace std;
const int MAX = 100004;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    float sum = 0;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    double m = sum / n;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] + arr[j] == 2 * m) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
