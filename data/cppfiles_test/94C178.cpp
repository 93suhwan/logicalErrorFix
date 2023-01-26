#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr;
    for (long long i = 0; i < n; i++) {
      long long h;
      cin >> h;
      long long topush = 1;
      while (h--) topush *= 10;
      arr.push_back(topush);
    }
    vector<long long> limits;
    for (long long i = 0; i < n - 1; i++) {
      limits.push_back(arr[i + 1] / arr[i] - 1);
    }
    long long rem = k + 1;
    long long current = 0;
    for (long long i = 0; i < n - 1; i++) {
      if (rem <= limits[i]) {
        current += arr[i] * rem;
        rem = 0;
        break;
      }
      current += (arr[i] * limits[i]);
      rem -= limits[i];
    }
    cout << current + (rem * arr[n - 1]) << "\n";
  }
  return 0;
}
