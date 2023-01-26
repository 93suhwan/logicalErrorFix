#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  cout << fixed << setprecision(10);
  while (t--) {
    int n;
    cin >> n;
    vector<long double> arr(n);
    long double total = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      total += arr[i];
    }
    sort(arr.begin(), arr.end(), greater<long double>());
    long double sum = 0, mx = LONG_MIN;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      total -= arr[i];
      mx = max(mx, (sum / (i + 1)) + (total / (n - i - 1)));
    }
    cout << mx << endl;
  }
}
