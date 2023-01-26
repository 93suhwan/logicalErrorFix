#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    unsigned long long k;
    cin >> n >> k;
    vector<long long> arr;
    vector<unsigned long long> prefix(n, 0);
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      arr.push_back(temp);
      sum += temp;
    }
    if (sum <= k) {
      cout << '0' << '\n';
    } else if (n == 1) {
      cout << (arr[0] - k) << '\n';
    } else {
      sort(arr.begin(), arr.end());
      prefix[0] = arr[0];
      for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
      }
      long long a;
      long long res = INT_MAX;
      for (int b = 1; b < n; b++) {
        a = (int)ceil((b * arr[0] - k + prefix[n - 1 - b]) / b);
        if (a < 0) {
          a = 0;
        }
        res = min(res, a + b);
      }
      cout << res << '\n';
    }
  }
  return 0;
}
