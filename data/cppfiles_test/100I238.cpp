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
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << arr[0] << endl;
      continue;
    } else {
      sort(arr, arr + n);
      vector<long long> v;
      for (long long i = 0; i < n - 1; i++) {
        v.push_back(arr[i + 1] - arr[i]);
      }
      if (n == 2) {
        cout << max(v[0], arr[0]) << endl;
      } else
        cout << *max_element(v.begin(), v.end()) << endl;
    }
  }
}
