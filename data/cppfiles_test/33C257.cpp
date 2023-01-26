#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int res = 0;
    for (int i = 0; i < n - 1; i++) {
      res = max(res, max(arr[i], arr[i + 1]) * 1LL * min(arr[i], arr[i + 1]));
    }
    cout << res << endl;
  }
  return 0;
}
