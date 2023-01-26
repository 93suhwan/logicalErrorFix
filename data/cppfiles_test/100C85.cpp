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
    long long arr[n];
    for (long long &x : arr) cin >> x;
    sort(arr, arr + n);
    long long maximal_min = arr[0], decr = arr[0];
    for (int i = 1; i < n; i++) {
      arr[i] -= decr;
      maximal_min = max(maximal_min, max({arr[i - 1], arr[i]}));
      decr += arr[i];
    }
    cout << maximal_min << '\n';
  }
}
