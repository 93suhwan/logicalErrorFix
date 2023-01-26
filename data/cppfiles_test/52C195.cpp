#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    double sum = 0;
    int arr[n];
    for (auto& i : arr) cin >> i;
    sort(arr, arr + n, greater<int>());
    for (int i = 1; i < n; i++) {
      sum += arr[i];
    }
    double num = sum / (n - 1);
    cout << fixed << setprecision(9) << arr[0] + num << "\n";
  }
  return 0;
}
