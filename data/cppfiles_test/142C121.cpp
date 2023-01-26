#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long m, n, c = 0;
    cin >> m >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < m; i++) {
      vector<long long> temp(n);
      for (long long j = 0; j < n; j++) {
        cin >> temp[j];
        arr[j] = max(arr[j], temp[j]);
      }
      sort(temp.begin(), temp.end());
      c = max(c, temp[n - 2]);
    }
    cout << min(c, *min_element(arr.begin(), arr.end())) << '\n';
  }
  return 0;
}
