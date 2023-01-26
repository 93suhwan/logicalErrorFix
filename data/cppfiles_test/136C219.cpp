#include <bits/stdc++.h>
using namespace std;
unsigned power(unsigned long long x, unsigned long long y,
               unsigned long long p) {
  unsigned res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  auto time = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; ++tt) {
    long long n;
    cin >> n;
    std::vector<long long> arr(n);
    for (long long i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      sum += arr[i];
    }
    long long tot = n * (n + 1) / 2;
    if (sum % tot != 0) {
      cout << "NO" << endl;
      continue;
    }
    sum = sum / tot;
    std::vector<long long> res(n, 0);
    res[0] = (sum - (arr[0]) + arr[n - 1]) / n;
    long long min_res = res[0];
    long long max_res = res[0];
    long long temp_sum = res[0];
    for (long long i = 1; i < n; ++i) {
      res[i] = (sum - arr[i] + arr[i - 1]) / n;
      temp_sum += res[i];
      min_res = min(min_res, res[i]);
      max_res = max(max_res, res[i]);
    }
    if (temp_sum != sum) {
      cout << "NO" << endl;
      continue;
    }
    if (min_res <= 0 || max_res > 1e9) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (long long i = 0; i < n; ++i) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
