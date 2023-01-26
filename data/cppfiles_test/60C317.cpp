#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  int n, k;
  long long n1;
  while (T--) {
    cin >> n;
    int arr[n];
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
    }
    int ans = mx;
    for (int i = 0; i < n; i++) {
      if (arr[i] == mx) continue;
      ans = ans & arr[i];
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
