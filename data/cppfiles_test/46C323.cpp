#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], cnt = 0;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int k = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > k) {
        cnt++;
        k = arr[i];
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
