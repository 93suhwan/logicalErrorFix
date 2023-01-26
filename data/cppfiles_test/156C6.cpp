#include <bits/stdc++.h>
using namespace std;
long long accuracy(long long a, long long b) {
  long long res = a / b;
  while (res * b > a) {
    res--;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    unsigned long long k;
    cin >> n >> k;
    vector<long long> arr;
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
      vector<unsigned long long> prefix(n + 1, 0);
      sort(arr.begin(), arr.end());
      for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
      }
      long long a = 0;
      long long res = 1e18;
      for (long long b = 0; b < n; b++) {
        a = arr[0] - accuracy(k - prefix[n - b] + arr[0], b + 1);
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
