#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  vector<long long> sum;
  int t, n, K;
  cin >> t;
  for (int i = (0); i < (t); i++) {
    cin >> n >> K;
    long long arr[n], maxi = 0;
    for (int j = (0); j < (n); j++) {
      cin >> arr[j];
    }
    for (int k = (0); k < (n - 2); k++) {
      long long s = ((k + 1) * (k + 2)) - (K * max(arr[k], arr[k + 1]));
      maxi = max(maxi, s);
    }
    sum.push_back(max(maxi, (n - (K * max(arr[0], arr[n - 1])))));
  }
  for (int p = (0); p < (sum.size()); p++) {
    cout << sum[p] << " \n";
  }
  return 0;
}
