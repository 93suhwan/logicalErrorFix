#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;
    sort(arr, arr + n);
    int maximal_min = arr[0], decr = arr[0];
    for (int i = 1; i < n; i++) {
      arr[i] -= decr;
      decr += arr[i];
      maximal_min = max(arr[i - 1], arr[i]);
    }
    cout << maximal_min << '\n';
  }
}
