#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
int noans = 0;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long maxi = arr[0];
    long long sum = arr[0];
    for (long long i = 1; i < n; i++) {
      arr[i] -= sum;
      maxi = max(maxi, arr[i]);
      sum += arr[i];
    }
    cout << maxi << "\n";
  }
}
