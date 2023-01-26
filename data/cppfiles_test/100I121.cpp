#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      s.insert(arr[i]);
    }
    if (n == 1) {
      cout << arr[0] << endl;
      continue;
    } else {
      sort(arr, arr + n);
      long long maxi = INT_MIN;
      for (long long i = 0; i < n - 1; i++) {
        maxi = max(maxi, arr[i + 1] - arr[i]);
      }
      if (n == 2) {
        cout << max(maxi, arr[0]) << endl;
        continue;
      }
      long long p = 0;
      if (s.size() != n) {
        maxi = max(maxi, p);
      }
      cout << maxi << endl;
    }
  }
}
