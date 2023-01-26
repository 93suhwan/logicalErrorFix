#include <bits/stdc++.h>
using namespace std;
void printvvi(vector<vector<long long>> arr) {
  cout << "[";
  for (long long i = 0; i < arr.size(); i++) {
    for (long long j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << ", ";
    }
    cout << endl;
  }
  cout << "]" << endl;
}
void printarr(long long arr[], long long n) {
  cout << "[";
  for (long long i = 0; i < n; i++) {
    cout << arr[i] << ", ";
  }
  cout << "]" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k < 3)
      cout << "NO" << endl;
    else if (k == 3) {
      if (m == n * (n - 1) / 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (m <= n * (n - 1) / 2 && m >= (n - 1)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
